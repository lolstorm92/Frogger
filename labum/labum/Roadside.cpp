#include "Roadside.h"
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"

Roadside::Roadside(const Vector3 & position) : StaticObject(position)
{

}


Roadside::~Roadside()
{
}

void Roadside::draw()
{
	glColor3f(0.604f, 0.831f, 0.451f);

	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	glScalef(2.f, .1f, 0.0f);

	glutSolidCube(1);
	glScalef(1.f, 1.f, 0.0f);

	glPopMatrix();
}
