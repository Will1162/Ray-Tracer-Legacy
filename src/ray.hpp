#ifndef WB_RT_RAY_HPP
#define WB_RT_RAY_HPP

#include "vec3.hpp"

class Ray
{
	public:
		Point3D origin;
		Vec3 direction;

		Ray(const Point3D &origin, const Vec3 &direction);
		Point3D At(double t) const;
};

Colour RayColour(const Ray &r);

#endif