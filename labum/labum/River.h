#pragma once
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"
class River : public StaticObject
{
public:
	River(const Vector3 & position);
	~River();
	virtual void draw();
};

