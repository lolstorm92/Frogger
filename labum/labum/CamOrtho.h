#ifndef CAMORTHO_H
#define CAMORTHO_H
#include "GL\glut.h"
#include "MyCamera.h"


class CamOrtho : public MyCamera
{

public:
	~CamOrtho();
	CamOrtho(int w, int h, int posX);
	virtual void Reshape(int w, int h);
	virtual void Reshape2(int w, int h, float objX, float objY, float objZ);
	void Refresh(){};
};


#endif
