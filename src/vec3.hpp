#ifndef WB_RT_VEC3_HPP
#define WB_RT_VEC3_HPP

class Vec3
{
	public:
		double x, y, z;

		Vec3();
		Vec3(double x, double y, double z);
		~Vec3(){};

		Vec3& operator+=(const Vec3 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		Vec3& operator*=(const double t)
		{
			x *= t;
			y *= t;
			z *= t;
			return *this;
		}

		Vec3& operator/=(const double t)
		{
			return *this *= 1 / t;
		}
		
		double length() const;
		double length_squared() const;
};

Vec3 operator+(const Vec3 &u, const Vec3 &v);
Vec3 operator-(const Vec3 &u, const Vec3 &v);
Vec3 operator*(const Vec3 &u, const Vec3 &v);
Vec3 operator*(double t, const Vec3 &v);
Vec3 operator*(const Vec3 &v, double t);
Vec3 operator/(Vec3 v, double t);
double Dot(const Vec3 &u, const Vec3 &v);
Vec3 Cross(const Vec3 &u, const Vec3 &v);
Vec3 UnitVector(Vec3 v);

using Point3D = Vec3;
using Colour = Vec3;

#endif