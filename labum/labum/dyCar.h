#pragma once
#include <stdlib.h>
#include "DynamincObject.h"
#include "Model.h"
#include "Header.h"
class dyCar : public DynamincObject
{
public:
	dyCar(const Vector3 & position);
	~dyCar();
	virtual void draw();
	void draw(Model * _model);
	virtual void move(Vector3 direction);
	virtual void update(double delta);
};

