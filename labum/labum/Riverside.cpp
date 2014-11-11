#include "Riverside.h"
#include <stdlib.h>
#include "StaticObject.h"
#include "Header.h"

Riverside::Riverside(const Vector3 & position) : StaticObject(position)
{
}


Riverside::~Riverside()
{
}


void Riverside::draw()
{
	glColor3f(.949f, 0.922f, 0.729f);
	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	glScalef(1.f, 1.f, 1.5f);
	glPushMatrix();
		glPushMatrix();
		glTranslatef(-1.f, 0.0f,0.0f);
		glScalef(.2f, .2f, .1f);
		glutSolidCube(1);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-.6f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .1f);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-.2f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .1f);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(.2f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .1f);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(.6f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .1f);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .1f);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
