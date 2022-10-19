#include <cmath>

#include "vec3.hpp"

Vec3::Vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vec3::Vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vec3::length() const
{
	return sqrt(length_squared());
}

double Vec3::length_squared() const
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

double Vec3Dot(const Vec3 &u, const Vec3 &v)
{
	return u.x * v.x
		 + u.y * v.y
		 + u.z * v.z;
}

Vec3 Vec3Cross(const Vec3 &u, const Vec3 &v)
{
	return Vec3(u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v.z,
				u.x * v.y - u.y * v.x);
}

Vec3 Vec3UnitVector(Vec3 v)
{
	return v / v.length();
}