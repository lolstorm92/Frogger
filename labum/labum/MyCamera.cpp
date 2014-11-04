#include "MyCamera.h"
#include "math.h"
#define _CRTDBG_MAP_ALLOC
MyCamera::MyCamera(int w, int h, int olhoX)
{
	_eyeX = olhoX;
	_largura = w;
	_altura = h;


}

void MyCamera::updateCam(int value){
	_eyeX += value;
	Reshape(_largura, _altura);
}

int MyCamera::getEyeX(){
	return _eyeX;
}

void MyCamera::SetState(int s)
{
	_state = s;
}
int  MyCamera::GetState()
{
	return _state;
}

void MyCamera::SetPos(float posx, float posy, float posz)
{
	_eyeX = posx;
	_eyeY = posy;
	_eyeZ = posz;

	Refresh();
}

float MyCamera::GetDistance()
{
	return _distance;
}

void MyCamera::GetDirectionVector(float &x, float &y, float &z)
{
	x = _cordX;
	y = _cordY;
	z = _cordZ;
}

void MyCamera::RotateYaw(float angle)
{
	_yaw += angle;

	Refresh();
}
void MyCamera::SetYaw(float angle)
{
	_yaw = angle;
}
float MyCamera::GetYaw()
{
	return _yaw;
}

void MyCamera::SetLastYaw(float angle)
{
	_lastYaw = angle;
}
float MyCamera::GetLastYaw()
{
	return _lastYaw;
}

void MyCamera::RotatePitch(float angle)
{
	const float limit = 89.0 * 3.1416f / 180.0;

	_pitch += angle;

	if (_pitch < -limit)
		_pitch = -limit;

	if (_pitch > limit)
		_pitch = limit;

	Refresh();
}
void MyCamera::SetPitch(float angle)
{
	_pitch = angle;
}
float MyCamera::GetPitch()
{
	return _pitch;
}



void MyCamera::setWindowsSize(int larg, int alt){
	_largura = larg;
	_altura = alt;
}
