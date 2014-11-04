#pragma once
class Vector3{
	public:
		Vector3(double x, double y, double z);
		Vector3();
		~Vector3(void);
		inline double getX(){ return _x; }
		inline double getY(){ return _y; }
		inline double getZ(){ return _z; }
		inline double getOriX(){ return _orix; }
		inline double getOriY(){ return _oriy; }
		inline double getOriZ(){ return _oriz; }
		inline void set(double x, double y, double z){ _x = x; _y = y; _z = z; }

		inline Vector3 Vector3::operator=(const Vector3 & vec) const { return Vector3(vec._x, vec._y, vec._z); }
		inline Vector3 Vector3::operator*(double num) const { return Vector3(_x * num, _y* num, _z* num); }
		inline friend Vector3 Vector3::operator*(float num, Vector3 const &vec){ return Vector3(vec._x*num, vec._y*num, vec._z*num); }
		inline Vector3 Vector3::operator+(const Vector3 &vec) const{ return Vector3(_x + vec._x, _y + vec._y, _z + vec._z); }
		inline Vector3 Vector3::operator-(const Vector3 &vec) const{ return Vector3(_x - vec._x, _y - vec._y, _z - vec._z); }
		double _x; 
		double _y;
		double _z;
		double _orix;
		double _oriy;
		double _oriz;
};
