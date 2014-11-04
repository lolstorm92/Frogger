#pragma once
#include "GameObject.h"

class DynamincObject :
	public GameObject
{

protected:
	Vector3 _speed;

public:
	char isdefined;
	DynamincObject();
	DynamincObject(const Vector3 & position) : GameObject(position), _speed(Vector3(0.0f, 0.0f, 0.0f)){};
	virtual ~DynamincObject(void);
	

	virtual void update(double delta_t = 0.5f) {_position.set(_position.getX() + _speed.getX() *delta_t, _position.getY() + _speed.getY()*delta_t, _position.getZ() + _speed.getZ()*delta_t);};
	inline void setSpeed(const Vector3 & speed) { _speed = speed; }
	inline void setSpeed(double x, double y, double z) { _speed.set(x, y, z); };
	inline  Vector3 getSpeed(){
		return _speed;
	}
	virtual bool checkColision(int col_cordX,int col_cordY){
		if (col_cordX >= _position.getX() + 1 && col_cordX <= _position.getX() + 12)
		if (col_cordY <= _position.getY() + 8 && col_cordY >= _position.getY())
				return true;
			else return false;
		else return false;
	}
};

