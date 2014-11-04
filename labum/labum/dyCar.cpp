#include "dyCar.h"


dyCar::dyCar(const Vector3 & position) : DynamincObject(position)
{
	//setSpeed(-0.01f, 0.0f, 0.0f);	
	//setSpeed((-1)*(rand() % 10 + 1)/10, 0, 0);
	//setSpeed(((float)(-1*(rand() % 10 + 1)))/1000, 0, 0);
	setSpeed(((float)(-0.6 * (rand() % 1 + 1))) / 100, 0, 0);


}


dyCar::~dyCar()
{
}

void dyCar::draw()
{
	{

		glColor3f(1.0f, 0.0f, 0.0f);
		//corpo todos
		glPushMatrix();
		glTranslatef(_position.getX(), _position.getY(), _position.getZ());
		
		
			//Pneus
			glPushMatrix();
			glColor3f(0.05f, 0.05f, 0.05f);
			glScalef(1.1f, 1.1, 0.5f);
			glTranslatef(0.0f, 0.0f, -0.04f);
				//Pneus da frente
				glPushMatrix();
				glTranslatef(-0.06f, 0.0f, 0.0f);
					//Pneu direito
					glPushMatrix();
						glTranslatef(0.0f, 0.035f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.03f, 0.05f, 0.1f);
						glutSolidTorus(0.2f, 0.5f, 32, 32);
					glPopMatrix();
					//Pneu Esquerdo
					glPushMatrix();
					glTranslatef(0.0f, -0.035f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.03f, 0.05f, 0.1f);
						glutSolidTorus(0.2f, 0.5f, 32, 32);
					glPopMatrix();
				glPopMatrix();
				//Pneus de tras
				glPushMatrix();
				glTranslatef(0.06f, 0.0f, 0.0f);
					//Pneu direito
					glPushMatrix();
					glTranslatef(0.0f, 0.035f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.03f, 0.05f, 0.1f);
						glutSolidTorus(0.2f, 0.5f, 32, 32);
					glPopMatrix();
					//Pneu Esquerdo
					glPushMatrix();
					glTranslatef(0.0f, -0.035f, 0.0f);
						glRotatef(90, 1.0f, 0.0f, 0.0f);
						glScalef(.03f, 0.05f, 0.1f);
						glutSolidTorus(0.2f, 0.5f, 32, 32);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			
			//Estrutura azul do carro
			glPushMatrix();
				glScalef(0.2f, 0.088f, 0.05f);
				glTranslatef(0.0f, 0.0f, 0.14f);
				glColor3f(0.482f, 0.588f, 0.69f);
				glutSolidCube(1);
				//Tejadilho
				glPushMatrix();
					glTranslatef(0.05f, 0.0f, 0.5f);
					glColor3f(0.353f, 0.475f, 0.588f);
					glScalef(.6f, .75f, 1.0f);
					glutSolidCube(1);
				glPopMatrix();
				//Luses
				glPushMatrix();
				glColor3f(1.0f, 1.0f, 0.224f);
				glTranslatef(-0.5f, 0.0f, 0.0f);
				//Luse Direita
				glPushMatrix();
				glTranslatef(0.0f, 0.3f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glScalef(.2f, 0.448f, 0.1f);
				glutSolidTorus(0.1f, 0.3f, 20, 20);
				glPopMatrix();
				//Luse Esquerda
				glPushMatrix();
				glTranslatef(0.0f, -0.3f, 0.0f);
				glRotatef(90, 1.0f, 0.0f, 0.0f);
				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glScalef(.2f, 0.448f, 0.1f);
				glutSolidTorus(0.1f, 0.3f, 20, 20);
				glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			
		glPopMatrix();

	glPopMatrix();



	}
}

/*void dyCar::update(double delta)
{
	//_position = _position + (_speed * delta);
	_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);
}*/

void dyCar::update(double delta)
{
	_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);

}
void dyCar::move( Vector3 direction)
{
	//setSpeed(_speed.getX(), _speed.getY(), _speed.getZ());
	//update(0.5);
}