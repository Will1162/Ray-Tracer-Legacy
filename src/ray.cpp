#include <cmath>

#include "globals.hpp"
#include "hittable_object.hpp"
#include "material.hpp"
#include "ray.hpp"

Ray::Ray()
{
	origin = Point3D(0.0, 0.0, 0.0);
	direction = Vec3(1.0, 0.0, 0.0);
}

Ray::Ray(const Point3D &origin, const Vec3 &direction)
{
	this->origin = origin;
	this->direction = direction;
}

Point3D Ray::At(double t) const
{
	return origin + t * direction;
}

Colour RayColour(const Ray& ray, const HittableObject& world, int depth)
{
	if (depth <= 0)
	{
		return Colour(0, 0, 0);
	}

	HitRecord rec;
	if (world.Hit(ray, 0.001, MATH_INF, rec))
	{
		Ray scattered;
		Colour attenuation;
		if (rec.material->Scatter(ray, rec, attenuation, scattered))
		{
			return attenuation * RayColour(scattered, world, depth - 1);
		}
		return Colour(0, 0, 0);
	}

	Vec3 unitDirection = UnitVector(ray.direction);
	double t = 0.5 * (unitDirection.y + 1.0);
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