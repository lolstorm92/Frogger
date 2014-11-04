
#include "GL\glut.h"
#include "MyCamera.h"


class CamPerspe : public MyCamera
{

public:
	~CamPerspe();
	CamPerspe(int w, int h, float posX, float posY, float posZ, float cetX, float cetY, float intcetZ);
	virtual void Reshape(int w, int h);
	virtual void Reshape2(int w, int h,float objX,float objY,float objZ);
	void Refresh();
};

