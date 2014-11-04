#pragma once
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"
class Riverside : public StaticObject
{
public:
	Riverside(const Vector3 & position);
	~Riverside();
	virtual void draw();
};
