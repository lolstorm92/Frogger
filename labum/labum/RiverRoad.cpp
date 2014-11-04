#include "RiverRoad.h"
#include "Vector3.h"
#include "Entity.h"
#include <GL/glut.h>


RiverRoad::RiverRoad(const Vector3 & position) : StaticObject(position)
{
}


RiverRoad::~RiverRoad(void)
{
}

void RiverRoad::draw()
{
	glColor3f(.949f, 0.922f, 0.729f);

	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());


	glScalef(2.f, .2f, .0f);
	glutSolidCube(1);


	glPopMatrix();

}