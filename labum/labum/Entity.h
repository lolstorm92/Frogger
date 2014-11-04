#pragma once

#include "Vector3.h"
class Entity
{
public:
	Entity();
	Entity(const Vector3 & position);
	~Entity();
protected:
	Vector3 _position;
	int sizeL;
public:
	inline Vector3 * getPosition(void) { return &_position; }
	inline Vector3 * setPosition(float x, float y, float z) {
		_position.set(x, y, z);
		return &_position; 
	}
	inline Vector3 * setPosition(const Vector3 & p) { _position = p; }

	inline int * getSizeL(void){ return &sizeL; }
	inline int * setSizeL(int size) { sizeL = size; }

	
};

