#include "LightSun.h"
LightSun::LightSun(){

}
LightSun::LightSun(GLenum light) {
	_GLenum = light;
	setAmbient(Vector4(0.8, 0.8, 0.8, 0.0));
	setDiffuse(Vector4( 0.08, 0.08, 0.08, 0.0));
	setSpecular(Vector4(0.4, 0.1, 0.4, 0.4));
	setPosition(Vector4(0.0, 0.0, 50, 0.0));
	setState(true);
}
LightSun::~LightSun(){

}
void LightSun::refresh(){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//limpa os buffers especificados
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);
	glEnable(_GLenum);
	glEnable(GL_CULL_FACE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLightfv(_GLenum, GL_AMBIENT, _ambient);
	glLightfv(_GLenum, GL_DIFFUSE, _diffuse);
	glLightfv(_GLenum, GL_SPECULAR, _specular);
	glLightfv(_GLenum, GL_POSITION, _position);
}
void LightSun::draw(){

	glPushMatrix();
	glColor3ub(255, 255, 0);
	glTranslatef(_position[0], _position[1], _position[2]);
	glScalef(5.21f, 5.21f, 5.21f);
	glutSolidSphere(1, 360, 22);
	glPopMatrix();
}
void LightSun::darkness(){
	setAmbient(Vector4(0.0, 0.0, 0.0, 0.0));
	setDiffuse(Vector4(0.0, 0.0, 0.0, 0.0));
	setSpecular(Vector4(0.0, 0.0, 0.0, 0.0));
}

void LightSun::daylight(){
	setAmbient(Vector4(0.8, 0.8, 0.8, 0.0));
	setDiffuse(Vector4(0.08, 0.08, 0.08, 0.0));
	setSpecular(Vector4(0.4, 0.1, 0.4, 0.4));
}