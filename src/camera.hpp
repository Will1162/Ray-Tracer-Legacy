#ifndef WB_RT_CAMERA_HPP
#define WB_RT_CAMERA_HPP

#include "ray.hpp"

class Camera
{
	private:
		Point3D origin;
		Vec3 horizontal;
		Vec3 vertical;
		Vec3 lowerLeftCorner;
		
	public:
		Camera();
		Ray GetRay(double u, double v) const;
};

#endif