#pragma once
#include "Entity.h"
class GameObject :
		public Entity
{
public:
	GameObject(const Vector3 & position) : Entity(position){};
	
	virtual ~GameObject(void){};
	virtual void draw(){};
	virtual void update(double delta_t = 0.0f){};
	virtual void move(Vector3 direction){};
	virtual bool checkColision(int xCord, int yCord){ return false; };

};

