#include "LightSource.h"
class LightStreetLamp : public LightSource
{
public:
	LightStreetLamp();
	LightStreetLamp(GLenum light);
	~LightStreetLamp();
	virtual void draw();
	void refresh();
	void darkness();
	void daylight();
private:

};
