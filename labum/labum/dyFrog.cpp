#include "dyFrog.h"

dyFrog::dyFrog(const Vector3 & position) : DynamincObject(position)
{
}


dyFrog::~dyFrog()
{
}

void dyFrog::draw()
{
		glColor3f(0.f, 0.f, 0.f);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

		GLfloat mat_ambient[] = { 0.7, 0.0, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.7, 0.0, 0.0, 1.0 };
		GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
		GLfloat mat_shininess[] = { 1.8 };

		glColor3f(1.0, 0.0, 0.0);

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		//corpo todo
		glPushMatrix();
		glTranslatef(_position.getX(), _position.getY(), _position.getZ());
		glScalef(0.4f, 0.4f, 0.15f);
		
		glColor3f(0.31f, 0.455f, 0.314f);
		//glColor3f(0.459, 0.553, 0.651); //REGANHA
		
		
		//movimentos e escalas de cada membro
			//Patas
			glPushMatrix();
			glTranslatef(0.0f, 0.0f, -0.2f);
			glScalef(0.1f, 0.1f, 0.2f);
				//Patas da Frente
				glPushMatrix();
				glTranslatef(0.0f, 0.3f, 0.0f);
					//Patas da direita
					glPushMatrix();
					glTranslatef(0.6f, 0.0f, 0.0f);
					glScalef(.16f, 0.16f, 0.16f);
					glutSolidSphere(1, 360, 22);
					glPopMatrix();
					//Patas da esquerda
					glPushMatrix();
					glTranslatef(-0.6f, 0.0f, 0.0f);
					glScalef(0.16f, 0.16f, 0.16f);
					glutSolidSphere(1, 360, 22);
					glPopMatrix();
				glPopMatrix();

				//Patas de Tras
				glPushMatrix();
				glTranslatef(0.0f, -0.35f, 0.0f);
					//Patas da direita
					glPushMatrix();
					glTranslatef(0.6f, 0.0f, 0.0f);
					glScalef(.16f, 0.16f, 0.16f);
					glutSolidSphere(1, 360, 22);
					glPopMatrix();
					//Patas da esquerda
					glPushMatrix();
					glTranslatef(-0.6f, 0.0f, 0.0f);
					glScalef(0.16f, 0.16f, 0.16f);
					glutSolidSphere(1, 360, 22);
					glPopMatrix();
				glPopMatrix();

			glPopMatrix();
			
			//Cabeca
			glPushMatrix();
			glTranslatef(0.0f, 0.075f, -0.07f);
			glScalef(0.04f, 0.04f, 0.1f);
			glutSolidSphere(1, 360, 22);
			glPopMatrix();

			//Corpo
			glPushMatrix();
			glTranslatef(0.0f, 0.003f, -0.14f);
			//glColor3f(0.612, 0.51, 0.40); //REGANHA
			glColor3f(0.227f, 0.337f, 0.231f);
			glScalef(0.065f, 0.065f, 0.1f);
			glutSolidSphere(1, 360, 22);
			glPopMatrix();

			//Olhos
			glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			glTranslatef(0.0f, 0.09f, -0.01f);
			glScalef(1.0f, 1.0f, 2.5f);

			glPushMatrix();
			glTranslatef(0.025f, 0.0f, 0.0f);
			glScalef(0.01f, 0.01f, 0.01f);
			glutSolidSphere(1, 360, 22);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-0.025f, 0.0f, 0.0f);
			glScalef(0.01f, 0.01f, 0.01f);
			glutSolidSphere(1, 360, 22);
			glPopMatrix();
			glPopMatrix();
		
		glPopMatrix();
}
void dyFrog::draw(Model * _model){
	
	glPushMatrix();
	glColor3f(0.31f, 0.455f, 0.314f);
	glTranslatef(_position.getX(), _position.getY(), _position.getZ()-0.03);
	glScalef(0.01f, 0.006f, 0.01f);
	glRotated(180, 0, 0, 1);
	glRotated(90, 1, 0, 0);
	_model->draw(MODEL_FROG);
	glPopMatrix();
}

void dyFrog::update(double delta)
{
	//_position = _position + (_speed * delta);
	/*_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);*/

	if (-1 >= _position.getX())
		_position.set(_position.getX() + .01, _position.getY(), _position.getZ());
	
	else if (1 <= _position.getX())
		_position.set(_position.getX() - .01, _position.getY(), _position.getZ());

	else if (-1 >= _position.getY())
		_position.set(_position.getX(), _position.getY() + .01, _position.getZ());
	
	else if( 1 <= _position.getY())
		_position.set(_position.getX(), _position.getY() - .01, _position.getZ());
	
	else
		_position.set(_position.getX() + _speed.getX() *delta, _position.getY() + _speed.getY()*delta, _position.getZ() + _speed.getZ()*delta);
}



void dyFrog::move(Vector3 direction)
{

}

bool dyFrog::checkColision(double xCord, double yCord, double xObject, double yObject){

	if (xCord - xObject <= _position.getX() && xCord + xObject >= _position.getX())
		if ((yCord + yObject >= _position.getY() && yCord - yObject <= _position.getY()))
			return true;
		else 
			return false;
	else 
		return false;
}
