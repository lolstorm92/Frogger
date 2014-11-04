#include "CamPerspeAll.h"
#include "math.h"
static GLfloat g_nearPlane = 0.1;
static GLfloat g_farPlane = 99999;

CamPerspeAll::CamPerspeAll(int w, int h, int posX)
{
	_eyeX = posX;
	_altura = w;
	_largura = h;
	_yaw = 0.0f;
	_lastYaw = 0.0f;
	_pitch = -3.1416f / 2;
	_distance = 0.4f;
	_state = STATE_TPS;
}

CamPerspeAll::~CamPerspeAll()
{

}

void CamPerspeAll::Reshape(int w, int h){
	_largura = w;
	_altura = h;
	glViewport(0, 0, (GLsizei)_largura, (GLsizei)_altura); //set the viewport to the current window specifications
	glMatrixMode(GL_PROJECTION); //set the matrix to projection
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)_largura / (GLfloat)_altura, g_nearPlane, g_farPlane); //set the perspective (angle of sight, width, height, ,depth)
	glMatrixMode(GL_MODELVIEW); //set the matrix back to model
}
void CamPerspeAll::Reshape2(int w, int h, float objX, float objY, float objZ){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, 0);
	//glScalef(0.3, 0.25, 0.1);
	//gluLookAt(_eyeX, -4.5, 2, 0, 0, 0, 0, 1, 0);
	/* ...where orbitDegrees is derived from mouse motion */
	gluLookAt(_eyeX, -2, 1.5, 0, 0, 0, 0, 1, 0);
}

