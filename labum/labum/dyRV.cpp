#include "dyRV.h"
#include <math.h>

dyRV::dyRV(const Vector3 & position) : DynamincObject(position)
{
	//setSpeed(-0.01f, 0.0f, 0.0f);	
	//setSpeed((-1)*(rand() % 10 + 1)/10, 0, 0);
	//tempoPassado = glutGet(GLUT_ELAPSED_TIME);
	////setSpeed((float)(1) *(0.02), 0, 0);
	//setSpeed(0.02, 0, 0);

	setSpeed(((float)(0.5 * (rand() % 1 + 1))) / 100, 0, 0);

}


dyRV::~dyRV()
{
}

void dyRV::draw()
{
	{

		glColor3f(1.0f, 0.0f, 0.0f);
		//corpo todo
		glPushMatrix();
		glTranslatef(_position.getX(), _position.getY(), _position.getZ());
		glRotatef(180, 0, 0, 1);


			//Pneus
			glPushMatrix();
				glColor3f(0.05f, 0.05f, 0.05f);
				glScalef(1.1f, 1.1, 1.1f);
				glTranslatef(0.0f, 0.0f, -0.001f);

				//Pneus da frente
				glPushMatrix();
				glTranslatef(0.0f, 0.0f, -0.12f);
					//Pneu direito
					glPushMatrix();
					glTranslatef(0.0f, 0.065f, 0.0f);
					glRotatef(90, 1.0f, 0.0f, 0.0f);
					glScalef(.05f, 0.05f, 0.1f);
					glutSolidTorus(0.12f, 0.5f, 32, 32);
					glPopMatrix();
					//Pneu Esquerdo
					glPushMatrix();
					glTranslatef(0.0f, -0.065f, 0.0f);
					glRotatef(90, 1.0f, 0.0f, 0.0f);
					glScalef(.05f, 0.05f, 0.1f);
					glutSolidTorus(0.12f, 0.5f, 32, 32);
					glPopMatrix();
				glPopMatrix();
				//Pneus de tras 1
				glPushMatrix();
				glTranslatef(0.15f, 0.0f, -0.12f);
					//Pneu direito
					glPushMatrix();
						glTranslatef(0.0f, 0.065f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.05f, 0.05f, 0.1f);
						glutSolidTorus(0.12f, 0.5f, 32, 32);
					glPopMatrix();
					//Pneu Esquerdo
					glPushMatrix();
						glTranslatef(0.0f, -0.065f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.05f, 0.05f, 0.1f);
						glutSolidTorus(0.12f, 0.5f, 32, 32);
					glPopMatrix();
				glPopMatrix();

				//Pneus de tras 2
				glPushMatrix();
				glTranslatef(0.3f, 0.0f, -0.12f);
					//Pneu direito
					glPushMatrix();
						glTranslatef(0.0f, 0.065f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.05f, 0.05f, 0.1f);
						glutSolidTorus(0.12f, 0.5f, 32, 32);
					glPopMatrix();
					//Pneu Esquerdo
					glPushMatrix();
						glTranslatef(0.0f, -0.065f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.05f, 0.05f, 0.1f);
						glutSolidTorus(0.12f, 0.5f, 32, 32);
					glPopMatrix();
				glPopMatrix();

			glPopMatrix();
			//Estrutura azul do carro
			glPushMatrix();
			glScalef(0.14f, 0.14f, 0.14f);
			glTranslatef(0.0f, 0.0f, -0.5f);

				//Luses
				glPushMatrix();
				glScalef(1.f, 1.f, 0.7f);
				glColor3f(1.0f, 1.0f, 0.224f);
				glTranslatef(-0.55f, 0.0f, -0.2f);
					//Luse Direita
					glPushMatrix();
						glTranslatef(0.0f, 0.35f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glRotatef(90, 0.0f, 1.0f, 0.0f);
						glScalef(.2f, 0.448f, 0.1f);
						glutSolidTorus(0.1f, 0.3f, 20, 30);
					glPopMatrix();
					//Luse Esquerda
					glPushMatrix();
						glTranslatef(0.0f, -0.35f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glRotatef(90, 0.0f, 1.0f, 0.0f);
						glScalef(.2f, 0.448f, 0.1f);
						glutSolidTorus(0.1f, 0.3f, 20, 30);
					glPopMatrix();
				glPopMatrix();

			glPushMatrix();
				glColor3f(0.078, 0.078, 0.078);
				glTranslatef(0.2f, 0.0f, 0.2f);
				glScalef(0.33f, 0.15f, 0.25f);
				glutSolidCube(1);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.23f, 0.40f, 0.87f);
				glScalef(1.0f, 1.0f, 0.8f);
				glutSolidCube(1);
			glPopMatrix();

			//Tejadilho
			glPushMatrix();
				glTranslatef(0.07f, 0.0f, 0.25f);
				glColor3f(0.08f, 0.19f, 0.486f);
				glScalef(.6f, .75f, .6f);
				glutSolidCube(1);
				glPopMatrix();
		glPopMatrix();

		//Estrutura cinzenta do carro

			glPushMatrix();
				glColor3f(0.761f, 0.761f, 0.761f);
				glTranslatef(0.235f, 0.0f, -0.04f);
				glScalef(0.31f, 0.14f, .15f);
				glutSolidCube(1);
			glPopMatrix();


	glPopMatrix();



	}
}

/*void dyCar::update(double delta)
{
//_position = _position + (_speed * delta);
_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);
}*/


void dyRV::update(double delta)
{
	//int asd = (round((delta * 11) / 5000));
	_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);
	//setSpeed((float)(tempoPassado)/1000000, 0 ,0);
	
	//setSpeed(((float)((1)*(rand() % 10 + 1))) / 1000, 0, 0);

	//setSpeed((round((delta * 11) / 5000)) / 100, 0.0f, 0.0f);
}
void dyRV::move(Vector3 direction)
{
	//setSpeed(_speed.getX(), _speed.getY(), _speed.getZ());
	//update(0.5);
}