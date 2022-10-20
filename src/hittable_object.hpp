#ifndef WB_RT_HITTABLE_OBJECT_HPP
#define WB_RT_HITTABLE_OBJECT_HPP

#include <memory>

#include "ray.hpp"

class Material;

struct HitRecord
{
	Point3D point;
	Vec3 normal;
	std::shared_ptr<Material> material;
	double t;
	bool frontFace;

	inline void SetFaceNormal(const Ray &ray, const Vec3 &outwardNormal)
	{
		frontFace = Dot(ray.direction, outwardNormal) < 0;
		normal = frontFace ? outwardNormal : Vec3(0.0, 0.0, 0.0) - outwardNormal;
	}
};

class HittableObject
{
	public:
		virtual bool Hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const = 0;
};

#endif