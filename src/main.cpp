#include <stdio.h>

#include "bitmap-io.hpp"

const int IMAGE_WIDTH = 768;
const int IMAGE_HEIGHT = 768;
const int BYTES_PER_PIXEL = 3;

int main()
{
	unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][BYTES_PER_PIXEL];
	char* imageFileName = (char*) "output.bmp";

	int rowsDone = 0;
	for (int i = 0; i < IMAGE_HEIGHT; i++)
	{
		for ( int j = 0; j < IMAGE_WIDTH; j++)
		{
			image[i][j][2] = (unsigned char) ( i * 255 / IMAGE_HEIGHT );
			image[i][j][1] = (unsigned char) ( j * 255 / IMAGE_WIDTH );
			image[i][j][0] = (unsigned char) ((i + j) * 255 / (IMAGE_HEIGHT+IMAGE_WIDTH));
		}
		
		rowsDone++;
		printf("Image done: %d%%\r", (int)(((float)rowsDone / (float)IMAGE_HEIGHT) * 100));
	}

	generateBitmapImage((unsigned char*) image, IMAGE_HEIGHT, IMAGE_WIDTH, imageFileName);

	return 0;
}