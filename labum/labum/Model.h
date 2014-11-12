#pragma once
#pragma warning (disable : 4996)
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include "Vector3.h"
#include "Vector4.h"
#include "Header.h"
#include "Material.h"
//Model array size
#define NUM_MODELS 6

//Model identifiers
enum {
	MODEL_FROG, MODEL_CAR, MODEL_ROAD, MODEL_WATER, MODEL_TRUCK, MODEL_LOG
};
typedef struct {
	std::vector<Vector3> vertices;
	std::vector<Vector3> normals;
	std::vector<std::vector<int>> faces; //vertex index / normal index / material index
	char* name;
} shape_t;
class Model
{
public:
	Model();
	~Model();
	void load();
	void draw(int model_id);
private:
	int models[NUM_MODELS]; //Saves all Models
	int getDisplayList(char* path);
	bool _loaded;
	
	void loadMaterials(char* material_filename, std::vector<material_t> & _materials, Material** & _loaded_materials);

	int findMaterialIndex(char* mat_name, std::vector<material_t> _materials);
	
};