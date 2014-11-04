#pragma once
#include "Vector3.h"
class Vector4 : public Vector3{

public:
	Vector4(double x, double y, double z, double w);
	Vector4();
	~Vector4(void);
	double _w;
	
	double _oriw;
	inline Vector4 Vector4::operator=(const Vector4 & vec) const { return Vector4(vec._x, vec._y, vec._z,vec._w); }
	inline Vector4 Vector4::operator*(double num) const { return Vector4(_x * num, _y* num, _z* num,_w* num); }
	inline friend Vector4 Vector4::operator*(float num, Vector4 const &vec){ return Vector4(vec._x*num, vec._y*num, vec._z*num, vec._w* num); }
	inline Vector4 Vector4::operator+(const Vector4 &vec) const{ return Vector4(_x + vec._x, _y + vec._y, _z + vec._z,_w + vec._w); }
	inline Vector4 Vector4::operator-(const Vector4 &vec) const{ return Vector4(_x - vec._x, _y - vec._y, _z - vec._z, _w - vec._w); }
	double getW(){ return _w; }
	double getOriW(){ return _oriw; }
};
