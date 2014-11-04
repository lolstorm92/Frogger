#pragma once
#pragma warning (disable : 4996)

#include <vector>
#include "Vector3.h"
#include "Header.h"
//Model array size
#define NUM_MODELS 3

//Model identifiers
enum {
	MODEL_FROG
};

class Model
{
public:
	Model();
	~Model();
	void load();
	void draw(int model_id);

private:
	int models[NUM_MODELS]; //dentro guardare los identificadores a las displaylist de cada modelo

	int getDisplayList(char* path);
};