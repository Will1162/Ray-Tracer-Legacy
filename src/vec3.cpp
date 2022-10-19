#include <cmath>

#include "vec3.hpp"

Vec3::Vec3()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vec3::Vec3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vec3::Length() const
{
	return sqrt(LengthSquared());
}

double Vec3::LengthSquared() const
{
	return x * x + y * y + z * z;
}

Vec3 operator+(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

Vec3 operator-(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

Vec3 operator*(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

Vec3 operator*(double t, const Vec3 &v)
{
	return Vec3(t * v.x, t * v.y, t * v.z);
}

Vec3 operator*(const Vec3 &v, double t)
{
	return t * v;
}

Vec3 operator/(Vec3 v, double t)
{
	return (1 / t) * v;
}

double Dot(const Vec3 &u, const Vec3 &v)
{
	return u.x * v.x
		 + u.y * v.y
		 + u.z * v.z;
}

Vec3 Cross(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v.z,
				u.x * v.y - u.y * v.x);
}

Vec3 UnitVector(Vec3 v)
{
	return v / v.Length();
}