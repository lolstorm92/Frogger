#pragma once
#include <stdlib.h>
#include "DynamincObject.h"
#include "Model.h"
#include "Header.h"

class dyFrog : public DynamincObject
{

public:
	dyFrog(const Vector3 & position);
	~dyFrog();
	void draw();
	void draw(Model * _model);
	virtual void move(Vector3 direction);
	virtual void update(double delta);
	virtual bool checkColision(double xCord, double yCord, double xObject, double yObject);
};

