#include <chrono>
#include <stdio.h>

#include "bitmap_io.hpp"
#include "camera.hpp"
#include "colour.hpp"
#include "globals.hpp"
#include "hittable_object_list.hpp"
#include "material.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "vec3.hpp"

unsigned char image[IMAGE_WIDTH][IMAGE_HEIGHT][BYTES_PER_PIXEL];

int main()
{
	char* imageFileName = (char*)"output.bmp";

	HittableObjectList world;
	
	auto materialGround  = std::make_shared<Lambertian>(Colour(0.0, 0.8, 0.7));
    auto materialCenter  = std::make_shared<Lambertian>(Colour(1.0, 0.5, 0.3));
    auto materialLeft    = std::make_shared<Metal>(Colour(0.8, 0.5, 0.5), 0.1);
    auto materialRight   = std::make_shared<Metal>(Colour(0.8, 0.6, 0.2), 0.5);
    auto materialBottom  = std::make_shared<Metal>(Colour(0.8, 0.8, 0.8), 0.0);

	world.Add(std::make_shared<Sphere>(Point3D( 0.0, -100.5, -1.0), 100.0, materialGround));
	world.Add(std::make_shared<Sphere>(Point3D( 0.0,    0.5, -1.0),   0.5, materialCenter));
	world.Add(std::make_shared<Sphere>(Point3D(-0.9,    0.0, -1.0),   0.5, materialLeft));
	world.Add(std::make_shared<Sphere>(Point3D( 0.9,    0.0, -1.0),   0.5, materialRight));
	world.Add(std::make_shared<Sphere>(Point3D( 0.0,   -0.3, -1.0),   0.2, materialBottom));

	Camera cam;

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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
		printf("Rendering: %d%%\r", (int)(((float)rowsDone / (float)IMAGE_HEIGHT) * 100));
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	printf("\nTime taken: %f s", (float)std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000);

	generateBitmapImage((unsigned char*)image, IMAGE_HEIGHT, IMAGE_WIDTH, imageFileName);

	return 0;
}