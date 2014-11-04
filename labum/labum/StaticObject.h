#pragma once
#include "GameObject.h"
class StaticObject :
	public GameObject
{
public:
	StaticObject(const Vector3 & position) : GameObject(position){};

	virtual ~StaticObject(){};

};

