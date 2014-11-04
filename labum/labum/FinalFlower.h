#pragma once
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"
class FinalFlower : public StaticObject
{
public:
	FinalFlower(const Vector3 & position);
	~FinalFlower(void);

	virtual void draw();
};