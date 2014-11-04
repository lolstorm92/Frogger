#include "CamOrtho.h"



CamOrtho::CamOrtho(int w, int h, int posX)
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

CamOrtho::~CamOrtho()
{
	
}

void CamOrtho::Reshape(int w, int h){

	float xmin = 0.0, xmax = 24.0, ymin = 0.0, ymax = 32.0;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (ratio < aspect)
	{
		float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		glOrtho(xmin - delta, xmax + delta, ymin, ymax, -10, 100);
	}
	else
	{
		float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		glOrtho(xmin, xmax, ymin - delta, ymax + delta, -10, 100);
	}
}
void CamOrtho::Reshape2(int w, int h, float objX, float objY, float objZ){


	//especifica qual a pilha de matrizes que esta activa
	//neste caso e' a matriz de projeccao
	glMatrixMode(GL_PROJECTION);
	//susbtituui o conteudo da matriz no topo da pilha actual pela identidade
	glLoadIdentity();
	SetPos(objX *_distance, objY*_distance, objZ *_distance);
	float rac = (float)w / h;
	if (rac > 1)
		glOrtho(rac*-1.0f, rac*1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
	else
		glOrtho(-1.0f, 1.0f, -1.0f / rac, 1.0f / rac, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 0,0 , 0, -1, 0, 1, 0);
}