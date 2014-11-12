#pragma once
#include <stdlib.h>
#include "DynamincObject.h"
#include "Header.h"
#include "Model.h"
class dyRV : public DynamincObject
{
private:
	int tempoPassado = 0;
public:
	dyRV(const Vector3 & position);
	~dyRV();
	virtual void draw();
	void draw(Model * _model);
	virtual void move(Vector3 direction);
	virtual void update(double delta);
	
};
