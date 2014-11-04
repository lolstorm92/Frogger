#include "Model.h"

Model::Model(){}
Model::~Model(){}

int Model::getDisplayList(char* path)
{

	std::vector<Vector3> vertexs;
	std::vector< std::pair<float, float> > texcoords;
	std::vector<Vector3> normals; //per vertex
	std::vector< std::vector< std::vector<int> > > faces;

	char c;
	FILE *fd = fopen(path, "r");
	
	do {
		char lineHeader[128];
		fscanf(fd, "%s", lineHeader);

		if (strcmp(lineHeader, "v") == 0)
		{
			Vector3 aux;
			/*
			fscanf(fd, "%c", &c); //espacio
			fscanf(fd, "%lf", &aux._x);
			fscanf(fd, "%c", &c); //espacio
			fscanf(fd, "%lf", &aux._y);
			fscanf(fd, "%c", &c); //espacio
			fscanf(fd, "%lf", &aux._z);
			*/
			fscanf(fd, "%lf %lf %lf\n", &aux._x, &aux._y, &aux._z);
			vertexs.push_back(aux);
			//fscanf(fd, "%c", &c); //salto de linea
		}
		if (strcmp(lineHeader, "vt") == 0)
		{
			std::pair<float, float> st;
			/*
			fscanf(fd, "%c", &c); //espacio
			fscanf(fd, "%f", &st.first);
			fscanf(fd, "%c", &c); //espacio
			fscanf(fd, "%f", &st.second);
			*/
			fscanf(fd, "%f %f\n", &st.first, &st.second);
			texcoords.push_back(st);
			//fscanf(fd, "%c", &c); //salto de linea
		}
		if (strcmp(lineHeader, "vn") == 0)
		{
			Vector3 aux;
			/*
			fscanf(fd, "%c", &c); 
			fscanf(fd, "%lf", &aux._x);
			fscanf(fd, "%c", &c); 
			fscanf(fd, "%lf", &aux._y);
			fscanf(fd, "%c", &c); 
			fscanf(fd, "%lf", &aux._z);
			*/
			fscanf(fd, "%lf %lf %lf\n", &aux._x, &aux._y, &aux._z);
			normals.push_back(aux);
			//fscanf(fd, "%c", &c); //salto de linea
		}
		if (strcmp(lineHeader, "f") == 0)
		{
			std::vector< std::vector<int> > points;
			std::vector<int> point(3);

			
			fscanf(fd, "%c", &c); //espacio
			int i = 0;
			if (c != '\n')	{
				do {
					i++;
					fscanf(fd, "%d/%d/%d", &point[0], &point[1], &point[2]);
					points.push_back(point);
					fscanf(fd, "%c", &c);
					if (i == 3)
						break;
					//espacio o salto de linea
					//fscanf(fd, "%c", &c); //espacio o salto de linea
				} while (c == ' ');

			faces.push_back(points);
			}
		}

	} while (!feof(fd));

	fclose(fd);

	int dl = glGenLists(1);
	glNewList(dl, GL_COMPILE);

	for (unsigned int i = 0; i<faces.size(); i++)
	{
		if (faces[i].size() == 3)
		{
			glBegin(GL_TRIANGLES);
			glTexCoord2f(texcoords[faces[i][0][1] - 1].first, texcoords[faces[i][0][1] - 1].second);
			glNormal3f(normals[faces[i][0][2] - 1]._x, normals[faces[i][0][2] - 1]._y, normals[faces[i][0][2] - 1]._z);
			glVertex3f(vertexs[faces[i][0][0] - 1]._x, vertexs[faces[i][0][0] - 1]._y, vertexs[faces[i][0][0] - 1]._z);

			glTexCoord2f(texcoords[faces[i][1][1] - 1].first, texcoords[faces[i][1][1] - 1].second);
			glNormal3f(normals[faces[i][1][2] - 1]._x, normals[faces[i][1][2] - 1]._y, normals[faces[i][1][2] - 1]._z);
			glVertex3f(vertexs[faces[i][1][0] - 1]._x, vertexs[faces[i][1][0] - 1]._y, vertexs[faces[i][1][0] - 1]._z);

			glTexCoord2f(texcoords[faces[i][2][1] - 1].first, texcoords[faces[i][2][1] - 1].second);
			glNormal3f(normals[faces[i][2][2] - 1]._x, normals[faces[i][2][2] - 1]._y, normals[faces[i][2][2] - 1]._z);
			glVertex3f(vertexs[faces[i][2][0] - 1]._x, vertexs[faces[i][2][0] - 1]._y, vertexs[faces[i][2][0] - 1]._z);
			glEnd();
		}
		else
		{
			glBegin(GL_QUADS);
			glTexCoord2f(texcoords[faces[i][0][1] - 1].first, texcoords[faces[i][0][1] - 1].second);
			glNormal3f(normals[faces[i][0][2] - 1]._x, normals[faces[i][0][2] - 1]._y, normals[faces[i][0][2] - 1]._z);
			glVertex3f(vertexs[faces[i][0][0] - 1]._x, vertexs[faces[i][0][0] - 1]._y, vertexs[faces[i][0][0] - 1]._z);

			glTexCoord2f(texcoords[faces[i][1][1] - 1].first, texcoords[faces[i][1][1] - 1].second);
			glNormal3f(normals[faces[i][1][2] - 1]._x, normals[faces[i][1][2] - 1]._y, normals[faces[i][1][2] - 1]._z);
			glVertex3f(vertexs[faces[i][1][0] - 1]._x, vertexs[faces[i][1][0] - 1]._y, vertexs[faces[i][1][0] - 1]._z);

			glTexCoord2f(texcoords[faces[i][2][1] - 1].first, texcoords[faces[i][2][1] - 1].second);
			glNormal3f(normals[faces[i][2][2] - 1]._x, normals[faces[i][2][2] - 1]._y, normals[faces[i][2][2] - 1]._z);
			glVertex3f(vertexs[faces[i][2][0] - 1]._x, vertexs[faces[i][2][0] - 1]._y, vertexs[faces[i][2][0] - 1]._z);

			glTexCoord2f(texcoords[faces[i][3][1] - 1].first, texcoords[faces[i][3][1] - 1].second);
			glNormal3f(normals[faces[i][3][2] - 1]._x, normals[faces[i][3][2] - 1]._y, normals[faces[i][3][2] - 1]._z);
			glVertex3f(vertexs[faces[i][3][0] - 1]._x, vertexs[faces[i][3][0] - 1]._y, vertexs[faces[i][3][0] - 1]._z);
			glEnd();
		}
	}

	glEndList();

	return dl;
}



void Model::load()
{
	models[MODEL_FROG] = getDisplayList("frog.obj");
}

void Model::draw(int model_id)
{
	glCallList(models[model_id]);
}