#ifndef WB_RT_GLOBALS_HPP
#define WB_RT_GLOBALS_HPP

#include <cstdlib>
#include <limits>

#define ASPECT_RATIO 1.7777777 // 16:9
#define IMAGE_WIDTH 800
#define IMAGE_HEIGHT (int)(IMAGE_WIDTH / ASPECT_RATIO)
#define BYTES_PER_PIXEL 3
#define SAMPLES_PER_PIXEL 50

#define MATH_PI 3.14159265358979323846
#define MATH_INF 0xffffffffffffffff

inline double DegToRad(double degrees)
{
	return degrees * MATH_PI / 180.0;
}

inline double RandDouble()
{
	return rand() / (RAND_MAX + 1.0);
}

inline double RandDouble(double min, double max)
{
	return min + (max - min) * RandDouble();
}

inline double Clamp(double x, double min, double max)
{
	if (x < min)
	{
		return min;
	}
	if (x > max)
	{
		return max;
	}
	return x;
}

#endif