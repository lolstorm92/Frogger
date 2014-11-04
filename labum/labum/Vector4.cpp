#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vector4.h"

Vector4::Vector4(double x = 0, double y = 0, double z = 0,double w =0)
{
	_x = x;
	_y = y;
	_z = z;
	_w = w;
	_orix = x;
	_oriy = y;
	_oriz = z;
	_oriw = w;
}
Vector4::Vector4(){

}
Vector4::~Vector4(void){

}

