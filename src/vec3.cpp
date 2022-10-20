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

bool Vec3::NearZero() const
{
	const double s = 1e-8;
	return (fabs(x) < s) && (fabs(y) < s) && (fabs(z) < s);
}

Vec3 Random()
{
	return Vec3(RandDouble(), RandDouble(), RandDouble());
}

Vec3 Random(double min, double max)
{
	return Vec3(RandDouble(min, max), RandDouble(min, max), RandDouble(min, max));
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

Vec3 RandomInUnitSphere()
{
	while (true)
	{
		Vec3 p = Random(-1, 1);
		if (p.LengthSquared() >= 1)
			continue;
		return p;
	}
}

Vec3 RandomInHemisphere(const Vec3 &normal)
{
	Vec3 inUnitSphere = RandomInUnitSphere();
	if (Dot(inUnitSphere, normal) > 0.0)
		return inUnitSphere;
	else
		return Vec3(0.0, 0.0, 0.0) - inUnitSphere;
}

Vec3 RandomUnitVector()
{
	return UnitVector(RandomInUnitSphere());
}

Vec3 Reflect(const Vec3 &v, const Vec3 &n)
{
	return v - 2 * Dot(v, n) * n;
}