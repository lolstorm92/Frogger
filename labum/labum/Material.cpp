#include "Model.h"
#include "Material.h"


Material::Material(void)
{
	_shininess = -1;
	setEmission(0, 0, 0, 0);
}

Material::Material(material_t material) {
	_ambient = material.ambient;
	_diffuse = material.diffuse;
	_specular = material.specular;
	_emission = material.emission;
	_shininess = material.shininess;
	_color = material.color;
}

Material::~Material(void)
{
}
