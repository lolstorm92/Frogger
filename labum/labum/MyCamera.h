#ifndef MYCAMERA_H
#define MYCAMERA_H
#include "GL\glut.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define STATE_FPS         0
#define STATE_TPS         1
#define STATE_TPS_FREE	  2

#define CAMERA_ZFAR   (TERRAIN_SIZE/sin(M_PI/4))
#define CAMERA_ZNEAR  0.01f
#define CAMERA_MAX_DISTANCE   0.1f
#define CAMERA_SPEED  ((M_PI/180*0.02))

class MyCamera{

public:
	MyCamera(int w, int h, int olhoX);
	MyCamera(){}

	//altura e largura da janela
	int _altura;
	int _largura;

	//cordenadas do centro do referencial
	float _cordX;
	float _cordY;
	float _cordZ;

	//cordenadas do olho da camera
	float _eyeX;
	float _eyeY;
	float _eyeZ;

	float _yaw, _lastYaw, _pitch; // Various rotation angles en radianes
	float _distance;


	int _state;

	virtual void Refresh()=0;

	void SetState(int s);
	int  GetState();
	
	virtual void Reshape(int w, int h) = 0;
	virtual void Reshape2(int w, int h, float objX, float objY, float objZ)=0;
	
	void updateCam(int value);

	int getEyeX();
	int getEyeY();
	int getEyeZ();
	void SetPos(float posx, float posy, float posz);

	float GetDistance();
	void GetDirectionVector(float &x, float &y, float &z);

	void  RotateYaw(float angle);
	void  SetYaw(float angle);
	float GetYaw();

	void  SetLastYaw(float angle);
	float GetLastYaw();

	void  RotatePitch(float angle);
	void  SetPitch(float angle);
	float GetPitch();


	void setWindowsSize(int larg, int alt);




};
#endif

