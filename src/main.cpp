#include <stdio.h>

#include "bitmap-io.hpp"
#include "colour.hpp"
#include "globals.hpp"
#include "vec3.hpp"

unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][BYTES_PER_PIXEL];

int main()
{
	char* imageFileName = (char*) "output.bmp";

	int rowsDone = 0;
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for ( int j = 0; j < IMAGE_WIDTH; j++)
		{
			Colour col(
				(double)i / (double)IMAGE_WIDTH * 255,
				(double)j / (double)IMAGE_WIDTH * 255,
				(double)(i + j) * 0.5 / (double)IMAGE_WIDTH * 255);

			WriteColour(i, j, IMAGE_WIDTH, IMAGE_HEIGHT, col);
		}
		
		rowsDone++;
		printf("Image done: %d%%\r", (int)(((float)rowsDone / (float)IMAGE_HEIGHT) * 100));
	}

	generateBitmapImage((unsigned char*) image, IMAGE_HEIGHT, IMAGE_WIDTH, imageFileName);

	return 0;
}