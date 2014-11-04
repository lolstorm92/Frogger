
#include "GL\glut.h"
#include "MyCamera.h"


class CamPerspeAll : public MyCamera
{

public:
	~CamPerspeAll();
	CamPerspeAll(int w, int h, int posX);
	virtual void Reshape(int w, int h);
	virtual void Reshape2(int w, int h, float objX, float objY, float objZ);
	void Refresh(){};
};

