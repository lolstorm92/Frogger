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

void drawMesh5()
{

	GLfloat qaBlack[] = { 0.52f, 0.516f, 0.516f, 0.20 };
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat qaWhite[] = { 0.20, 0.20, 0.20, 0.20 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 1110.0);


	//glBegin(GL_TRIANGLE_FAN);
	//
	//	glColor3f(0.67f, 0.20, 0.1);
	//	glVertex3f(-0.5, -0.5, 0.1);
	//	glColor3f(0.07f, 0.20, 0.1);
	//	glVertex3f(-0.5, 0.5, 0.1);
	//	glColor3f(0.07, 0.20, 0.1);
	//	glVertex3f(0.5, 0.5, 0.1);
	//	glColor3f(0.07, 0.10, 0.1);
	//	glVertex3f(0.5, -0.5, 0.1);
	//
	//glEnd();

	const GLfloat vert = 0.1;
	for (int a = -5; a < 5; a = a + 2)
	{
		for (int i = -5; i < 5; i = i + 1)
		{
			glBegin(GL_POLYGON);

			glColor3f(.949f, 0.922f, 0.729f);

			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(i*vert, vert*a + 0.2, -0.1);
			glVertex3f(i*vert, vert*a, -0.1);
			glVertex3f(i*vert + 0.1, vert*a, -0.1);

			glEnd();

			glBegin(GL_POLYGON);

			glColor3f(.949f, 0.922f, 0.729f);

			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(i*vert, vert*a + 0.2, -0.2);
			glVertex3f(i*vert + 0.1, vert*a, -0.2);
			glVertex3f(i*vert + 0.1, vert*a + 0.2, -0.2);

			glEnd();

		}
	}

}

void RiverRoad::draw()
{
	glColor3f(.949f, 0.922f, 0.729f);

	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());


	glScalef(2.f, .2f, .0f);
	glPushMatrix();
	drawMesh5();
	glPopMatrix();


	glPopMatrix();

}