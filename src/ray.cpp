#include "ray.hpp"

Ray::Ray(const Point3D &origin, const Vec3 &direction)
{
	this->origin = origin;
	this->direction = direction;
}

Point3D Ray::At(double t) const
{
	return origin + t * direction;
}