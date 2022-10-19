#include "hittable_object_list.hpp"

HittableObjectList::HittableObjectList(std::shared_ptr<HittableObject> object)
{
	Add(object);
}

void HittableObjectList::Clear()
{
	objects.clear();
}

void HittableObjectList::Add(std::shared_ptr<HittableObject> object)
{
	objects.push_back(object);
}

bool HittableObjectList::Hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const
{
	HitRecord tempRec;
	bool hitAnything = false;
	double closestSoFar = tMax;

	for (const auto &object : objects)
	{
		if (object->Hit(ray, tMin, closestSoFar, tempRec))
		{
			hitAnything = true;
			closestSoFar = tempRec.t;
			rec = tempRec;
		}
	}

	return hitAnything;
}