#include "Road.h"
#include "Vector3.h"
#include "Entity.h"
#include <GL/glut.h>
Road::Road(const Vector3 & position) : StaticObject(position)
{
}
Road::~Road(void)
{
}
void drawlines()
{
	for (float i = 1.; i > -1.01; i = i - 0.1)
	{
		glPushMatrix();
		glTranslatef(i, -0.5f, -0.001f);
		glScalef(1.0f, 1.0f, 0.02f);
		glPushMatrix();
		glTranslatef(0.0f, 0.20f, 0.03f);
		glColor3f(0.9f, 0.95f, 0.95f);
		glScalef(0.025f, 0.011f, 0.1f);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.0f, -0.01f, 0.03f);
		glColor3f(0.9f, 0.95f, 0.95f);
		glScalef(0.025f, 0.011f, 0.1f);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.0f, -0.20f, 0.03f);
		glColor3f(0.9f, 0.95f, 0.95f);
		glScalef(0.025f, 0.011f, 0.1f);
		glutSolidCube(1);
		glPopMatrix();
		glPopMatrix();
	}
}
void drawMesh()
{
	GLfloat qaBlack[] = { 0.52f, 0.516f, 0.516f, 0.20 };
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat qaWhite[] = { 0.20, 0.20, 0.20, 0.20 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);
	//glBegin(GL_TRIANGLE_FAN);
	//
	// glColor3f(0.67f, 0.20, 0.1);
	// glVertex3f(-0.5, -0.5, 0.1);
	// glColor3f(0.07f, 0.20, 0.1);
	// glVertex3f(-0.5, 0.5, 0.1);
	// glColor3f(0.07, 0.20, 0.1);
	// glVertex3f(0.5, 0.5, 0.1);
	// glColor3f(0.07, 0.10, 0.1);
	// glVertex3f(0.5, -0.5, 0.1);
	//
	//glEnd();
	const GLfloat vert = 0.1;
	for (int a = -5; a < 5; a = a + 2)
	{
		for (int i = -5; i < 5; i = i + 1)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.22f, 0.216f, 0.216f);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(i*vert, vert*a + 0.2, -0.1);
			glVertex3f(i*vert, vert*a, -0.1);
			glVertex3f(i*vert + 0.1, vert*a, -0.1);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.22f, 0.216f, 0.216f);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(i*vert, vert*a + 0.2, -0.2);
			glVertex3f(i*vert + 0.1, vert*a, -0.2);
			glVertex3f(i*vert + 0.1, vert*a + 0.2, -0.2);
			glEnd();
		}
	}
}
void Road::draw()
{
	//glColor3f(0.22f, 0.216f, 0.216f);
	//glPushMatrix();
	//glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	//
	//glScalef(2.f, .8f, .0f);
	//glutSolidCube(1);
	//glPopMatrix();
	//
	glPushMatrix();
		glTranslatef(_position.getX(), _position.getY(), _position.getZ());
		glScalef(2.f, .8f, .0f);
		//glBegin(GL_POLYGON);
		//{
		// glColor3f(0.07, 0.20, 0.1);
		// glVertex3f(-0.5, 0.5, -0.1);
		// glVertex3f(-0.5, -0.5, -0.1);
		// glVertex3f(-0.5 + 0.5, -0.5, -0.1);
		//}
		//glEnd();
		// glBegin(GL_POLYGON);
		// {
		// glColor3f(0.07, 0.20, 0.1);
		// glVertex3f(0, 0.5, -0.1);
		// glVertex3f(0, -0.5, -0.1);
		// glVertex3f(0 + 0.5, -0.5, -0.1);
		// }
		glPushMatrix();
			//glEnd();
			drawMesh();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, 0.5, -1.2);
			drawlines();
		glPopMatrix();
	glPopMatrix();
}