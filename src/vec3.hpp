#ifndef WB_RT_VEC3_HPP
#define WB_RT_VEC3_HPP

#include <cmath>

class vec3
{
	public:
		float x, y, z;

		vec3::vec3(float x, float y, float z);
		~vec3();

		vec3& operator+=(const vec3 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		vec3& operator*=(const double t)
		{
			x *= t;
			y *= t;
			z *= t;
			return *this;
		}

		vec3& operator/=(const double t)
		{
			return *this *= 1 / t;
		}

		double length() const
		{
			return sqrt(length_squared());
		}

		double length_squared() const
		{
			return x * x + y * y + z * z;
		}
};

using point3 = vec3;
using color = vec3;

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
	return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
	return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
	return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline vec3 operator*(double t, const vec3 &v)
{
	return vec3(t * v.x, t * v.y, t * v.z);
}

inline vec3 operator*(const vec3 &v, double t)
{
	return t * v;
}

inline vec3 operator/(vec3 v, double t)
{
	return (1 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v)
{
	return u.x * v.x
		 + u.y * v.y
		 + u.z * v.z;
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
	return vec3(u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v.z,
				u.x * v.y - u.y * v.x);
}

inline vec3 unit_vector(vec3 v)
{
	return v / v.length();
}

#endif