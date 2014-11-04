#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vector3.h"

Vector3::Vector3(double x = 0, double y = 0, double z = 0)
{
	_x = x;
	_y = y;
	_z = z;
	_orix = x;
	_oriy = y;
	_oriz = z;
}
Vector3::Vector3(){

}
Vector3::~Vector3(void){

}

