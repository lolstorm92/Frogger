#pragma once
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"
class Road : public StaticObject
{
public:
	Road(const Vector3 & position);
	~Road(void);

	virtual void draw();
};

