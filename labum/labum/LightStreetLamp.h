#include "LightSource.h"
class LightStreetLamp : public LightSource
{
public:
	LightStreetLamp();
	LightStreetLamp(GLenum light, float pos_x, float pos_y, float pos_z, float pos_w, Vector3 direction);
	~LightStreetLamp();
	virtual void draw();
	void refresh();
	void darkness();
	void daylight();
private:

};
