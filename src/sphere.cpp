#include <cmath>

#include "sphere.hpp"

Sphere::Sphere()
{
	centre = Point3D(0.0, 0.0, 0.0);
	radius = 1.0;
}

Sphere::Sphere(Point3D centre, double radius)
{
	this->centre = centre;
	this->radius = radius;
}

bool Sphere::Hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const
{
	Vec3 oc = ray.origin - centre;
	double a = ray.direction.LengthSquared();
	double halfB = Dot(oc, ray.direction);
	double c = oc.LengthSquared() - radius * radius;
	double discriminant = halfB * halfB - a * c;
	
	if (discriminant < 0)
		return false;

	double sqrtDisc = sqrt(discriminant);
	double root = (-halfB - sqrtDisc) / a;
	if (root < tMin || tMax < root)
	{
		root = (-halfB + sqrtDisc) / a;
		if (root < tMin || tMax < root)
			return false;
	}

	rec.t = root;
	rec.point = ray.At(rec.t);
	Vec3 outwardNormal = (rec.point - centre) / radius;
	rec.SetFaceNormal(ray, outwardNormal);

	return true;
}