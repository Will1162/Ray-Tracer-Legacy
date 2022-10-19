#include <stdio.h>

#include "bitmap_io.hpp"
#include "camera.hpp"
#include "colour.hpp"
#include "globals.hpp"
#include "hittable_object_list.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "vec3.hpp"

unsigned char image[IMAGE_WIDTH][IMAGE_HEIGHT][BYTES_PER_PIXEL];

int main()
{
	char* imageFileName = (char*)"output.bmp";

	HittableObjectList world;
	world.Add(std::make_shared<Sphere>(Point3D(0, 0, -1), 0.5));
	world.Add(std::make_shared<Sphere>(Point3D(0, -100.5, -1), 100));

	Camera cam;

	int rowsDone = 0;
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for (int j = 0; j < IMAGE_WIDTH; j++)
		{
			Colour pixelColour(0, 0, 0);
			for (int k = 0; k < SAMPLES_PER_PIXEL; k++)
			{
				double u = (j + RandDouble()) / (IMAGE_WIDTH - 1);
				double v = (i + RandDouble()) / (IMAGE_HEIGHT - 1);
				Ray r = cam.GetRay(u, v);
				pixelColour += RayColour(r, world, MAX_DEPTH);
			}

			WriteColour(i, j, IMAGE_WIDTH, IMAGE_HEIGHT, pixelColour);
		}
		
		rowsDone++;
		printf("Image done: %d%%\r", (int)(((float)rowsDone / (float)IMAGE_HEIGHT) * 100));
	}

	generateBitmapImage((unsigned char*)image, IMAGE_HEIGHT, IMAGE_WIDTH, imageFileName);

	return 0;
}