#pragma once
#include <stdlib.h>
#include "DynamincObject.h"
#include "Header.h"

class dyLog : public DynamincObject
{
private:
	bool _isColided;
public:
	
	dyLog(const Vector3 & position);
	~dyLog();
	virtual void draw();
	virtual void move(Vector3 direction);
	virtual void update(double delta);

	bool getIsColided(){ return _isColided;}
	void setIsColided(bool isColided){ _isColided = isColided; }

};
