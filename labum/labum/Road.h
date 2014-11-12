#pragma once
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"
#include "Model.h"
class Road : public StaticObject
{
public:
	Road(const Vector3 & position);
	~Road(void);

	virtual void draw();
	void draw(Model * _model);

};

