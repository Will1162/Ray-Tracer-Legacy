#include <cmath>

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
	double t = HitSphere(Point3D(0, 0, -1), 0.5, r);
	if (t > 0.0)
	{
		Vec3 N = UnitVector(r.At(t) - Vec3(0, 0, -1));
		return 0.5 * Colour(N.x + 1, N.y + 1, N.z + 1);
	}

	Vec3 unitDir = UnitVector(r.direction);
	t = 0.5 * (unitDir.y + 1.0);
	return (1.0 - t) * Colour(1.0, 1.0, 1.0) + t * Colour(0.5, 0.7, 1.0);
}

double HitSphere(const Point3D& centre, float radius, const Ray& ray)
{
	Vec3 oc = ray.origin - centre;
	double a = ray.direction.LengthSquared();
	double halfB = Dot(oc, ray.direction);
	double c = oc.LengthSquared() - radius * radius;
	double discriminant = halfB * halfB - a * c;

	if (discriminant < 0)
	{
		return -1.0;
	}
	else
	{
		return (-halfB - sqrt(discriminant)) / a;
	}
}