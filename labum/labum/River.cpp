#include "River.h"
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"

River::River(const Vector3 & position) : StaticObject(position)
{
}


River::~River()
{
}

void River::draw()
{
	glColor3f(0.443f, 0.725f, 0.89f);

	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	glScalef(2.f, .9f, .0f);
	glutSolidCube(1);

	glPopMatrix();


}