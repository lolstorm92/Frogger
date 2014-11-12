#include "Model.h"

Model::Model(){}
Model::~Model(){}

int Model::getDisplayList(char* path)
{
	ifstream file(path);
	int v = 0, vn = 0, f = 0, s = -1, material = -1;
	std::vector<shape_t> _shapes;
	std::vector<material_t> _materials;
	Material** _loaded_materials=NULL;
	char* buffer = new char[8192];
	while (file.peek() != -1) {
		file.getline(&buffer[0], 8192);
		string sbuffer(&buffer[0]);

		if (sbuffer.empty()) {
			continue;
		}

		if (sbuffer.size() > 0) {
			if (sbuffer[sbuffer.size() - 1] == '\n') sbuffer.erase(sbuffer.size() - 1);
		}
		if (sbuffer.size() > 0) {
			if (sbuffer[sbuffer.size() - 1] == '\r') sbuffer.erase(sbuffer.size() - 1);
		}

		const char* line = sbuffer.c_str();
		char letter[1024];
		sscanf(line, "%s", letter);

		if (letter[0] == '\0') {
			continue;
		}
		else if (letter[0] == '#') {
			continue;
		}
		else if (letter[0] == 'o') {
			char name[1024];
			line += 2;
			sscanf(line, "%s", name);
			shape_t shape;
			shape.name = name;
			_shapes.push_back(shape);
			s++;
		}
		else if (letter[0] == 'v' && letter[1] == 'n') {
			line += 3;
			float x, y, z;
			sscanf(line, "%f %f %f", &x, &y, &z);
			_shapes[s].normals.push_back(Vector3(x, y, z));
			vn++;
		}
		else if (letter[0] == 'v') {
			line += 2;
			float x, y, z;
			sscanf(line, "%f %f %f", &x, &y, &z);
			_shapes[s].vertices.push_back(Vector3(x, y, z));
			v++;
		}
		else if (letter[0] == 'f') {
			line += 2;
			int v1, n1, v2, n2, v3, n3;
			sscanf(line, "%d//%d %d//%d %d//%d", &v1, &n1, &v2, &n2, &v3, &n3);
			std::vector<int> face;
			face.push_back(v1);
			face.push_back(n1);
			face.push_back(v2);
			face.push_back(n2);
			face.push_back(v3);
			face.push_back(n3);
			face.push_back(material);
			_shapes[s].faces.push_back(face);
			f++;
		}
		else if (strcmp("usemtl", letter) == 0) {
			line += 7;
			char mat_name[1024];
			sscanf(line, "%s", mat_name);
			material = findMaterialIndex(mat_name,_materials);
		}
		else if (strcmp("mtllib", letter) == 0) {
			line += 7;
			char filename[1024];
			sscanf(line, "%s", filename);
			loadMaterials(filename,_materials,_loaded_materials);
		}

	}
	_loaded = true;

	int dl = glGenLists(1);
	glNewList(dl, GL_COMPILE);

	int current_material = -1;
	if (_loaded == true) {
		for (size_t s = 0; s < _shapes.size(); s++) {
			vector<vector<int>> faces = _shapes[s].faces;
			vector<Vector3> vertices = _shapes[s].vertices;
			vector<Vector3> normals = _shapes[s].normals;
			
			for (size_t f = 0; f < faces.size(); f++) {
				
				int material_index = faces[f][6];
				if (material_index != current_material) {
					Material* m = _loaded_materials[material_index];
					m->apply();
					m->color();
					current_material = material_index;
				}
				glBegin(GL_TRIANGLES);
				for (size_t v = 0; v < faces[f].size() - 1; v += 2) {
					int vIndex = faces[f][v];
					int nIndex = faces[f][v + 1];
					for (int i = 0; i < s; i++)
					{
						vIndex = vIndex - _shapes[i].vertices.size();
						nIndex = nIndex - _shapes[i].normals.size();
					}
					Vector3 vertex = vertices[vIndex - 1];
					Vector3 normal = normals[nIndex - 1];
					glNormal3f(normal.getX(), normal.getY(), normal.getZ());
					glVertex3f(vertex.getX(), vertex.getY(), vertex.getZ());
				}
				glEnd();
			}
		}
	}

	glEndList();

	return dl;
}
void Model::loadMaterials(char* material_filename, std::vector<material_t>& _materials, Material** & _loaded_materials) {
	char full_name[1024] = "models/";
	strcat(full_name, material_filename);
	ifstream mfile(full_name);
	char *buffer = new char[8192];
	int m = -1;

	while (mfile.peek() != -1){
		mfile.getline(&buffer[0], 8192);
		string sbuffer(&buffer[0]);

		if (sbuffer.empty()) {
			continue;
		}

		if (sbuffer.size() > 0) {
			if (sbuffer[sbuffer.size() - 1] == '\n') sbuffer.erase(sbuffer.size() - 1);
		}
		if (sbuffer.size() > 0) {
			if (sbuffer[sbuffer.size() - 1] == '\r') sbuffer.erase(sbuffer.size() - 1);
		}

		const char* line = sbuffer.c_str();
		char command[10];
		sscanf(line, "%s", command);
		if (strcmp("newmtl", command) == 0) {
			line += 7;
			char material_name[1024];
			sscanf(line, "%s", material_name);
			material_t material;
			material.name = new char[1024];
			strcpy(material.name, material_name);
			_materials.push_back(material);
			m++;
		}
		else if (strcmp("Cl", command) == 0) {
			line += 3;
			float r, g, b;
			sscanf(line, "%f %f %f", &r, &g, &b);
			_materials[m].color = new Vector3(r, g, b);
		}
		else if (strcmp("Ka", command) == 0) {
			line += 3;
			float r, g, b, a;
			sscanf(line, "%f %f %f", &r, &g, &b);
			_materials[m].ambient = new Vector4(r, g, b, 1);
		}
		else if (strcmp("Ks", command) == 0) {
			line += 3;
			float r, g, b, a;
			sscanf(line, "%f %f %f", &r, &g, &b);
			_materials[m].specular = new Vector4(r, g, b, 1);
		}
		else if (strcmp("Kd", command) == 0) {
			line += 3;
			float r, g, b, a;
			sscanf(line, "%f %f %f", &r, &g, &b);
			_materials[m].diffuse = new Vector4(r, g, b, 1);
		}
		else if (strcmp("Ke", command) == 0) {
			line += 3;
			float r, g, b, a;
			sscanf(line, "%f %f %f", &r, &g, &b);
			_materials[m].emission = new Vector4(r, g, b, 1);
		}
		else if (strcmp("Sh", command) == 0) {
			line += 3;
			float s;
			sscanf(line, "%f", &s);
			_materials[m].shininess = s;
		}

	}

	_loaded_materials = new Material*[_materials.size()];
	for (int i = 0; i < _materials.size(); i++) {
		_loaded_materials[i] = new Material(_materials[i]);
	}
}
int Model::findMaterialIndex(char* mat_name, std::vector<material_t> _materials) {
	for (size_t i = 0; i < _materials.size(); i++) {
		if (strcmp(mat_name, _materials[i].name) == 0){
			return i;
		}
	}
	return -1;
}


void Model::load()
{
	
	models[MODEL_FROG] = getDisplayList("models/frogn2.obj");
	models[MODEL_CAR] = getDisplayList("models/cartrans.obj");
	models[MODEL_ROAD] = getDisplayList("models/road.obj");
	models[MODEL_WATER] = getDisplayList("models/waternotrans.obj");
	
	models[MODEL_TRUCK] = getDisplayList("models/camiao.obj");
	models[MODEL_LOG] = getDisplayList("models/log.obj");
}

void Model::draw(int model_id)
{
	glCallList(models[model_id]);
}