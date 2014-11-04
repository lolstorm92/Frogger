#pragma once
#include <stdlib.h>
#include "DynamincObject.h"
#include "Header.h"

class dyTurtle : public DynamincObject
{
private:
	bool _isColided;
public:
	dyTurtle(const Vector3 & position);
	~dyTurtle();
	virtual void draw();
	virtual void move(Vector3 direction);
	virtual void update(double delta);

	bool getIsColided(){ return _isColided; }
	void setIsColided(bool isColided){ _isColided = isColided; }
};