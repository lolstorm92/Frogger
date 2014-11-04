#ifndef LightSource_H
#define LightSource_H
#include "Header.h"
#include "Vector4.h"
class LightSource
{
	public:
		LightSource();
		LightSource(GLenum _GLenum);
		~LightSource(void);
		bool getState(){ return _state; };
		void setState(bool state){ _state = state; };
		GLenum getNum();
		void setPosition(Vector4  position){
			_position[0] = position.getX();
			_position[1] = position.getY();
			_position[2] = position.getZ();
			_position[3] = position.getW();
		}
		void setDirection(Vector3  direction){
			_direction[0] = direction.getX();
			_direction[1] = direction.getY();
			_direction[2] = direction.getZ();
		}
		void setCutOff(double cut_off){
			_cut_off = cut_off;
		}
		void setExponent(double exponent){
			_exponent = exponent;
		}
		void setAmbient(Vector4  ambient){
			_ambient[0] = ambient.getX();
			_ambient[1] = ambient.getY();
			_ambient[2] = ambient.getZ();
			_ambient[3] = ambient.getW();
		}
		void setDiffuse(Vector4  diffuse){
			_diffuse[0] = diffuse.getX();
			_diffuse[1] = diffuse.getY();
			_diffuse[2] = diffuse.getZ();
			_diffuse[3] = diffuse.getW();
		}
		void setSpecular(Vector4  specular){
			_specular[0] = specular.getX();
			_specular[1] = specular.getY();
			_specular[2] = specular.getZ();
			_specular[3] = specular.getW();
		}
		virtual void draw(){};
	protected:
		GLfloat  _ambient[4];
		GLfloat  _diffuse[4];
		GLfloat  _specular[4];
		GLfloat  _position[4];
		GLfloat _direction[3];
		double _cut_off;
		double _exponent;
		GLenum _GLenum;
		bool _state;

		
};
#endif