#include <stdio.h>

#include "bitmap-io.hpp"
#include "colour.hpp"
#include "ray.hpp"
#include "globals.hpp"
#include "vec3.hpp"

unsigned char image[IMAGE_WIDTH][IMAGE_HEIGHT][BYTES_PER_PIXEL];

int main()
{
	char* imageFileName = (char*) "output.bmp";

	double viewportHeight = 2.0;
	double viewportWidth = ASPECT_RATIO * viewportHeight;
	double focalLength = 1.0;

	Point3D origin = Point3D(0, 0, 0);
	Vec3 horizontal = Vec3(viewportWidth, 0, 0);
	Vec3 vertical = Vec3(0, viewportHeight, 0);
	Vec3 lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

	int rowsDone = 0;
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			double u = double(j) / (IMAGE_WIDTH - 1);
			double v = double(i) / (IMAGE_HEIGHT - 1);

			Ray ray = Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
			Colour col = RayColour(ray);

			WriteColour(i, j, IMAGE_WIDTH, IMAGE_HEIGHT, col * 255.0);
		}
		
		rowsDone++;
		printf("Image done: %d%%\r", (int)(((float)rowsDone / (float)IMAGE_HEIGHT) * 100));
	}

	generateBitmapImage((unsigned char*) image, IMAGE_HEIGHT, IMAGE_WIDTH, imageFileName);

	return 0;
}