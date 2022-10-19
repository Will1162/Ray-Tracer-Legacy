#ifndef WB_RT_HITTABLE_OBJECT_LIST_HPP
#define WB_RT_HITTABLE_OBJECT_LIST_HPP

#include <memory>
#include <vector>

#include "hittable_object.hpp"

class HittableObjectList : public HittableObject
{
	public:
		std::vector<std::shared_ptr<HittableObject>> objects;

		HittableObjectList(){};
		HittableObjectList(std::shared_ptr<HittableObject> object);

		void Clear();
		void Add(std::shared_ptr<HittableObject> object);
		virtual bool Hit(const Ray &ray, double tMin, double tMax, HitRecord &rec) const override;
};

#endif