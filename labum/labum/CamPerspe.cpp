#include "Header.h"
#include "CamPerspe.h"
#define _USE_MATH_DEFINES
#include <math.h>
static GLfloat g_nearPlane = 0.1;
static GLfloat g_farPlane = 9999;

CamPerspe::CamPerspe(int w, int h, float posX, float posY, float posZ, float cetX, float cetY, float cetZ)
{
	_eyeX = posX;
	_eyeX = posY;
	_eyeX = posZ;
	_cordX = cetX;
	_cordY = cetY;
	_cordZ = cetZ;
	_altura = w;
	_largura = h;
	_yaw = 7.8 ;
	_lastYaw = M_PI / 2;
	_pitch =  -M_PI/4;
	_distance = 0.4f;
	_state = STATE_TPS;
}

CamPerspe::~CamPerspe()
{

}

void  CamPerspe::Refresh()
{
	/*
	_cordX = cos(_yaw) * cos(_pitch);
	_cordY = sin(_pitch);
	_cordZ = sin(_yaw) * cos(_pitch);*/
	_cordX = cos(_pitch) * cos(_yaw);
	_cordY = cos(_pitch)* sin(_yaw);
	_cordZ = sin(_pitch);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(_eyeX, _eyeY, _eyeZ, _eyeX + _cordX, _eyeY + _cordY, _eyeZ + _cordZ, 0, 0, 1);
	
	}

void CamPerspe::Reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
	glMatrixMode(GL_PROJECTION); //set the matrix to projection
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, g_nearPlane, g_farPlane); //set the perspective (angle of sight, width, height, ,depth)
	glMatrixMode(GL_MODELVIEW); //set the matrix back to model
}
void CamPerspe::Reshape2(int w, int h,float objX,float objY,float objZ){
	/*






													  Y
	_cordX = cos(_yaw) * cos(_pitch);			      |_______ Z
	_cordY = sin(_pitch);                            / 
	_cordZ = sin(_yaw) * cos(_pitch);              X

													  Z
	_cordX = cos(_yaw) * cos(_pitch);			      |_______ Y
	_cordY = sin(_yaw) * cos(_pitch)			     /
	_cordZ = sin(_pitch);						   X
		
													 Z
	_cordX = sin(_yaw) * cos(_pitch);			      |_______ X
	_cordY = cos(_yaw) * cos(_pitch)			     /
	_cordZ = sin(_pitch);						   Y	
		


													Z
    _cordX = sin(_yaw) * cos(_pitch);				| _____ Y
    _cordY = sin(_yaw) * sin(_pitch);			   / 
    _cordZ = cos(_pitch);						 X

													z
	_cordX = sin(_yaw) * sin(_pitch);				| _____ X
	_cordY = sin(_yaw) * cos(_pitch);			   /
	_cordZ = cos(_pitch);						 Y

														Y
														| _____ X
	_cordX = sin(_yaw) * cos(_pitch);                  /
	_cordY = cos(_pitch);                            Z
	_cordZ = sin(_yaw) * sin(_pitch);





	*/

	_cordX = cos(_pitch) * cos(_yaw);
	_cordY = cos(_pitch)* sin(_yaw);
	_cordZ = sin(_pitch);
	/*
	_cordX = sin(_yaw);
	_cordZ = -cos(_yaw);
	*/
	SetPos(objX - _cordX*_distance, objY - _cordY*_distance, objZ - _cordZ*_distance);
	//SetPos(objX, objY, objZ);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(_eyeX, _eyeY, _eyeZ, _eyeX + _cordX, _eyeY + _cordY, _eyeZ + _cordZ, 0, 0, 1);
	
}

