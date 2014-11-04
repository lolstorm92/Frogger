#pragma once
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"
class Roadside : public StaticObject
{
public:
	Roadside(const Vector3 & position);
	~Roadside(void);
	virtual void draw();
};

