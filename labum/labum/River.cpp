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


void drawMeshW()
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

			glColor3f(0.443f, 0.725f, 0.89f);

			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(i*vert, vert*a + 0.2, -0.1);
			glVertex3f(i*vert, vert*a, -0.1);
			glVertex3f(i*vert + 0.1, vert*a, -0.1);

			glEnd();

			glBegin(GL_POLYGON);

			glColor3f(0.443f, 0.725f, 0.89f);

			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(i*vert, vert*a + 0.2, -0.2);
			glVertex3f(i*vert + 0.1, vert*a, -0.2);
			glVertex3f(i*vert + 0.1, vert*a + 0.2, -0.2);

			glEnd();

		}
	}

}
void River::draw()
{
	glColor3f(0.443f, 0.725f, 0.89f);

	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	glScalef(2.f, .9f, .0f);
	/*glutSolidCube(1);*/
	glPushMatrix();
	drawMeshW();
	glPopMatrix();

	glPopMatrix();


}
void River::draw(Model * _model){

	glPushMatrix();
	//glColor3f(0.31f, 0.455f, 0.314f);
	glTranslatef(_position.getX(), _position.getY(), _position.getZ() - 0.1);
	glScalef(0.19f, 0.172f, 0.1f);
	glRotated(180, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	_model->draw(MODEL_WATER);
	glPopMatrix();
}