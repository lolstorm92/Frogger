#pragma once
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"
class RiverRoad : public StaticObject
{
public:
	RiverRoad(const Vector3 & position);
	~RiverRoad(void);

	virtual void draw();
};
