#include "LightStreetLamp.h"
LightStreetLamp::LightStreetLamp(){

}
LightStreetLamp::LightStreetLamp(GLenum light, float pos_x, float pos_y, float pos_z, float pos_w,Vector3 direction) {
	_GLenum = light;
	setAmbient(Vector4(0.3, 0.3, 0.3, 1.0));
	setDiffuse(Vector4(0.7, 0.7, 0.7, 1.0));
	setSpecular(Vector4(0.5, 0.5, 0.5, 1.0));
	setPosition(Vector4(pos_x, pos_y, pos_z, pos_w));
	setDirection(Vector3(direction._x, direction._y, direction._z));
	setState(true);
	glEnable(_GLenum);
}
LightStreetLamp::~LightStreetLamp(){

}
void LightStreetLamp::refresh(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glColor3ub(255, 255, 0);
	glTranslatef(_position[0], _position[1], _position[2]);
	glScalef(0.01f, 0.01f, 0.01f);
	glutSolidSphere(1, 360, 22);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	*/
	}
void LightStreetLamp::darkness(){
	setAmbient(Vector4(0.0, 0.0, 0.0, 0.0));
	setDiffuse(Vector4(0.0, 0.0, 0.0, 0.0));
	setSpecular(Vector4(0.0, 0.0, 0.0, 0.0));
}

void LightStreetLamp::daylight(){
	setAmbient(Vector4(0.3, 0.3, 0.3, 1.0));
	setDiffuse(Vector4(0.7, 0.7, 0.7, 1.0));
	setSpecular(Vector4(0.5, 0.5, 0.5, 1.0));
}