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
	
	for (float i = 1.; i > -1.01; i=i-0.1)
	{

		glPushMatrix();
		glTranslatef(i, -0.5f, -0.001f);
		glScalef(1.0f, 1.0f, 0.02f);
			glPushMatrix();
			glTranslatef(0.0f, 0.20f, 0.01f);
				glColor3f(0.9f, 0.95f, 0.95f);
				glScalef(0.025f, 0.011f, 0.1f);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0f, -0.01f, 0.01f);
				glColor3f(0.9f, 0.95f, 0.95f);
				glScalef(0.025f, 0.011f, 0.1f);
				glutSolidCube(1);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0f, -0.20f, 0.01f);
				glColor3f(0.9f, 0.95f, 0.95f);
				glScalef(0.025f, 0.011f, 0.1f);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

	}
	//glPushMatrix();
	//glTranslatef(.5f, 0.0f, 0.0f);
	//	glPushMatrix();
	//		glTranslatef(0.0f, 0.25f, 0.0f);
	//		glColor3f(0.9f, 0.95f, 0.95f);
	//		glScalef(0.025f, 0.011f, 0.0f);
	//		glutSolidCube(1);
	//	glPopMatrix();
	//	glPushMatrix();
	//		glTranslatef(0.0f, 0.0f, 0.0f);
	//		glColor3f(0.9f, 0.95f, 0.95f);
	//		glScalef(0.025f, 0.011f, 0.0f);
	//		glutSolidCube(1);
	//	glPopMatrix();
	//	glPushMatrix();
	//		glTranslatef(0.0f, -0.25f, 0.0f);
	//		glColor3f(0.9f, 0.95f, 0.95f);
	//		glScalef(0.025f, 0.011f, 0.0f);
	//		glutSolidCube(1);
	//	glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(.4f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, 0.0f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, 0.0f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(.3f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(.2f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(.1f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(.0f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-.1f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-.2f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-.3f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-.4f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, -0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(-.5f, 0.0f, 0.0f);
	//glPushMatrix();
	//glTranslatef(0.0f, 0.25f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f);
	//glColor3f(0.9f, 0.95f, 0.95f);
	//glScalef(0.025f, 0.011f, .1f);
	//glutSolidCube(1);
	//glPopMatrix();
	//glPushMatrix();
	//	glTranslatef(0.0f, -0.25f, 0.0f);
	//	glColor3f(0.9f, 0.95f, 0.95f);
	//	glScalef(0.025f, 0.011f, .1f);
	//	glutSolidCube(1);
	//	glPopMatrix();
	//glPopMatrix();
}

void Road::draw()
{
	/*
	glColor3f(0.22f, 0.216f, 0.216f);

	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	

	glScalef(2.f, .8f, .0f);
	glutSolidCube(1);
	glPopMatrix();
	*/	
	//glClear(GL_COLOR_BUFFER_BIT);
	
	
	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	/**/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	// Set material properties
	GLfloat qaBlack[] = { 0.0f, 0.0f, 0.0f, 1.0 };
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBlack);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

	// Draw square with many little squares
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	const GLfloat kqDelta = .01;
	for (int i = -40; i < 40; ++i) {
		for (int j = -110; j < 110; ++j) {
			//glColor3f(0.22f, 0.216f, 0.216f);
			glVertex3f(j*kqDelta, i*kqDelta, 0);
			glVertex3f((j + 1)*kqDelta, i*kqDelta, 0);
			glVertex3f((j + 1)*kqDelta, (i + 1)*kqDelta, 0);
			glVertex3f(j*kqDelta, (i + 1)*kqDelta, 0);
		}
	}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
		drawlines();
	glPopMatrix();
	
}

