#pragma once
#include "Vector4.h"
#include <GL\glut.h>

typedef struct {
	Vector4* ambient;
	Vector4* diffuse;
	Vector4* specular;
	Vector4* emission;
	Vector3* color; //color if lightning is disabled
	GLfloat shininess;
	char* name;
} material_t;

class Material
{
private:
	Vector4* _ambient;
	Vector4* _diffuse;
	Vector4* _specular;
	Vector4* _emission;
	Vector3* _color;
	GLfloat _shininess;
public:
	Material(void);
	Material(material_t);
	~Material(void);
	void setAmbient(double r, double g, double b, double reflectance) {
		_ambient = new Vector4(r, g, b, reflectance);
	}
	void setDiffuse(double r, double g, double b, double reflectance) {
		_diffuse = new Vector4(r, g, b, reflectance);
	}
	void setSpecular(double r, double g, double b, double reflectance) {
		_specular = new Vector4(r, g, b, reflectance);
	}
	void setEmission(double r, double g, double b, double intensity) {
		_emission = new Vector4(r, g, b, intensity);
	}
	void setShininess(GLfloat shininess) {
		_shininess = shininess;
	}

	void apply() {
		if (_ambient && _diffuse && _specular && _shininess != -1) {
			GLfloat aux_ambient[] = { _ambient->_x, _ambient->_y, _ambient->_z, _ambient->_w };
			GLfloat aux_diffuse[] = { _diffuse->_x, _diffuse->_y, _diffuse->_z, _diffuse->_w };
			GLfloat aux_specular[] = { _specular->_x, _specular->_y, _specular->_z, _specular->_w };
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, aux_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, aux_diffuse);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, aux_specular);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);
		}
		/*
		if (_emission){
			GLfloat aux_emission[] = { _emission->_x, _emission->_y, _emission->_z, _emission->_w };
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, aux_emission);
		}
		*/
	}
	void color() {
		
		//glColor3f(_color->getX(), _color->getY(), _color->getZ());
		glColor3f(_diffuse->_x, _diffuse->_y, _diffuse->_z);
	}
};

