#include "LightStreetLamp.h"
LightStreetLamp::LightStreetLamp(){

}
LightStreetLamp::LightStreetLamp(GLenum light) {
	_GLenum = light;
	setAmbient(Vector4(0.1, 0.1, 0.1, 1.0));
	setDiffuse(Vector4(0.9, 0.9, 0.9, 1.0));
	setSpecular(Vector4(0.5, 0.5, 0.5, 1.0));
	setPosition(Vector4(-0.6f, -0.1f, 0.4f, 1.0f));
	setDirection(Vector3(0.0f, 0.0f, -1.0));
	setState(true);
}
LightStreetLamp::~LightStreetLamp(){

}
void LightStreetLamp::refresh(){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	glEnable(_GLenum);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
	glLightfv(_GLenum, GL_AMBIENT, _ambient);
	glLightfv(_GLenum, GL_DIFFUSE, _diffuse);
	glLightfv(_GLenum, GL_SPECULAR, _specular);
	glLightfv(_GLenum, GL_POSITION, _position);
	glLightf(_GLenum, GL_SPOT_CUTOFF, 45);
	glLightfv(_GLenum, GL_SPOT_DIRECTION, _direction);
	//glLightf(_GLenum, GL_SPOT_EXPONENT, 10.0);
}
void LightStreetLamp::draw(){
	/*
	glPushMatrix();
	glColor3ub(255, 255, 0);
	glTranslatef(_position[0], _position[1], _position[2]);
	glScalef(0.01f, 0.01f, 0.01f);
	glutSolidSphere(1, 360, 22);
	glPopMatrix();*/
}
void LightStreetLamp::darkness(){
	setAmbient(Vector4(0.0, 0.0, 0.0, 0.0));
	setDiffuse(Vector4(0.0, 0.0, 0.0, 0.0));
	setSpecular(Vector4(0.0, 0.0, 0.0, 0.0));
}

void LightStreetLamp::daylight(){
	setAmbient(Vector4(0.8, 0.8, 0.8, 0.0));
	setDiffuse(Vector4(0.08, 0.08, 0.08, 0.0));
	setSpecular(Vector4(0.4, 0.1, 0.4, 0.4));
}