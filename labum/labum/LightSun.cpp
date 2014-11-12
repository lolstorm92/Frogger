#include "LightSun.h"
LightSun::LightSun(){

}
LightSun::LightSun(GLenum light) {
	_GLenum = light;
	setAmbient(Vector4(0.8, 0.8, 0.8, 1.0));
	setDiffuse(Vector4(0.2, 0.2, 0.2, 1.0));
	setSpecular(Vector4(0.5, 0.5, 0.5, 0.5));
	setPosition(Vector4(0.0, 0.0, 10, 0.0));
	setState(true);
	glEnable(_GLenum);
}
LightSun::~LightSun(){

}
void LightSun::refresh(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightfv(_GLenum, GL_AMBIENT, _ambient);
	glLightfv(_GLenum, GL_DIFFUSE, _diffuse);
	glLightfv(_GLenum, GL_SPECULAR, _specular);
	glLightfv(_GLenum, GL_POSITION, _position);
}
void LightSun::draw(){
	/*
	
	glPushMatrix();
	glColor3ub(255, 255, 0);
	glTranslatef(_position[0], _position[1], _position[2]);
	glScalef(5.21f, 5.21f, 5.21f);
	glutSolidSphere(1, 360, 22);
	glPopMatrix();
	*/
	}
void LightSun::darkness(){
	setAmbient(Vector4(0.0, 0.0, 0.0, 1.0));
	setDiffuse(Vector4(0.0, 0.0, 0.0, 1.0));
	setSpecular(Vector4(0.0, 0.0, 0.0, 1.0));
}

void LightSun::daylight(){
	setAmbient(Vector4(0.8, 0.8, 0.8, 1.0));
	setDiffuse(Vector4(0.2, 0.2, 0.2, 1.0));
	setSpecular(Vector4(0.5, 0.5, 0.5, 0.5));
}