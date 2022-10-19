#include <stdio.h>
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

Colour RayColour(const Ray &r)
{
	Vec3 unitDir = UnitVector(r.direction);
	double t = 0.5 * (unitDir.y + 1.0);
	return (1.0 - t) * Colour(1.0, 1.0, 1.0) + t * Colour(0.5, 0.7, 1.0);
}