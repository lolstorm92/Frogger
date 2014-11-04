#include "dyLog.h"

dyLog::dyLog(const Vector3 & position) : DynamincObject(position)
{
	setSpeed(((float)(-0.1 * (rand() % 1 + 1))) / 100, 0, 0);

}


dyLog::~dyLog()
{
}

void dyLog::draw()
{
	{
		glColor3f(0.65f, 0.45f, 0.36f);
		//corpo todo
		//corpo todo
		glPushMatrix();
		glTranslatef(_position.getX(), _position.getY(), _position.getZ());

		//movimentos e escalas de cada membro
		glPushMatrix();
		glTranslatef(-0.35f, 0.0f, 0.0f);
		glScalef(0.15f, 0.1f, 0.1f);
			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			gluCylinder(quadratic, 0.48f, 0.48f, 3.0f, 32, 32);
		glPopMatrix();
		glPopMatrix();



	}
}

void dyLog::update(double delta)
{
	//_position = _position + (_speed * delta);
	_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);

}

void dyLog::move(Vector3 direction)
{
	//setSpeed(direction);
	//update(1);
}