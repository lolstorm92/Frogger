#include "LightSource.h"
class LightSun : public LightSource
{
public:
	LightSun();
	LightSun(GLenum light) ;
	~LightSun();
	virtual void draw();
	void refresh();
	void darkness();
	void daylight();
private:

};
