#ifndef WB_RT_MATERIAL_HPP
#define WB_RT_MATERIAL_HPP

#include "hittable_object.hpp"
#include "ray.hpp"

struct HitRecord;

class Material
{
	public:
		virtual bool Scatter(const Ray& rayIn, const HitRecord& hitRecord, Colour& attenuation, Ray& scattered) const = 0;
};

class Lambertian : public Material
{
	public:
		Colour albedo;

		Lambertian(const Colour& albedo)
		{
			this->albedo = albedo;
		}

		virtual bool Scatter(const Ray& rayIn, const HitRecord& hitRecord, Colour& attenuation, Ray& scattered) const override
		{
			Vec3 scatterDir = hitRecord.normal + RandomUnitVector();

			if (scatterDir.NearZero())
			{
				scatterDir = hitRecord.normal;
			}

			scattered = Ray(hitRecord.point, scatterDir);
			attenuation = albedo;
			return true;
		}
};

class Metal : public Material
{
	public:
		Colour albedo;

		Metal(const Colour& albedo)
		{
			this->albedo = albedo;
		}

		virtual bool Scatter(const Ray& rayIn, const HitRecord& hitRecord, Colour& attenuation, Ray& scattered) const override
		{
			Vec3 reflected = Reflect(UnitVector(rayIn.direction), hitRecord.normal);
			scattered = Ray(hitRecord.point, reflected);
			attenuation = albedo;
			return (Dot(scattered.direction, hitRecord.normal) > 0);
		}
};

#endif