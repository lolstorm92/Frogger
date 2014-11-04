#include "dyTurtle.h"

dyTurtle::dyTurtle(const Vector3 & position) : DynamincObject(position)
{
	//setSpeed(((float)((rand() % 10 + 1))) / 100, 0, 0);
	setSpeed(((float)(0.1 * (rand() % 1 + 1))) / 100, 0, 0);


}


dyTurtle::~dyTurtle()
{
}

void dyTurtle::draw()
{
	{
		glColor3f(0.21f, 0.23f, 0.18f);
		//corpo todo
		//corpo todo
		glPushMatrix();
		glTranslatef(_position.getX(), _position.getY(), _position.getZ());

		//movimentos e escalas de cada membro
		//glPushMatrix();
		//glTranslatef(-0.35f, 0.0f, 0.0f);
		//glScalef(0.15f, 0.1f, 0.3f);
		//GLUquadricObj *quadratic;
		//quadratic = gluNewQuadric();
		//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		//gluCylinder(quadratic, 0.48f, 0.48f, 3.0f, 32, 32);
		//glPopMatrix();
		//glPopMatrix();
		
			glPushMatrix();
			glScalef(0.05f, 0.05f, 0.05f);
			glTranslatef(-0.35f, 0.0f, 0.0f);
				glPushMatrix();
					glTranslatef(0.0f, 0.0f, 0.0f);
					glutSolidSphere(1, 360, 22);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-2.0f, 0.0f, 0.0f);
					glutSolidSphere(1, 360, 22);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-4.0f, 0.0f, 0.0f);
					glutSolidSphere(1, 360, 22);
				glPopMatrix();
			glPopMatrix();

		glPopMatrix();

	}
}

void dyTurtle::update(double delta)
{
	//_position = _position + (_speed * delta);
	_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);

}

void dyTurtle::move(Vector3 direction)
{
	//setSpeed(direction);
	//update(1);
}