#include "FinalFlower.h"
#include "Vector3.h"
#include "Entity.h"
#include <GL/glut.h>

#define SIZE_FLOWER 0.35f

FinalFlower::FinalFlower(const Vector3 & position) : StaticObject(position)
{
}


FinalFlower::~FinalFlower(void)
{
}

void FinalFlower::draw()
{
	glColor3f(0.54, .89, .624);
	
	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
		
		glPushMatrix();
		glTranslatef(-0.8f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .0f);
		glutSolidSphere(SIZE_FLOWER, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.4f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .0f);
		glutSolidSphere(SIZE_FLOWER, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .0f);
		glutSolidSphere(SIZE_FLOWER, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.4f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .0f);
		glutSolidSphere(SIZE_FLOWER, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.8f, 0.0f, 0.0f);
		glScalef(.2f, .2f, .0f);
		glutSolidSphere(SIZE_FLOWER, 32, 32);
		glPopMatrix();

	glPopMatrix();

}