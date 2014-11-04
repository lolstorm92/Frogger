#pragma once
#include <stdlib.h>
#include "DynamincObject.h"
#include "Header.h"
class dyRV : public DynamincObject
{
private:
	int tempoPassado = 0;
public:
	dyRV(const Vector3 & position);
	~dyRV();
	virtual void draw();
	virtual void move(Vector3 direction);
	virtual void update(double delta);
	
};
