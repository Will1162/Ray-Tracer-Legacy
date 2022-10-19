#ifndef WB_RT_COLOUR_HPP
#define WB_RT_COLOUR_HPP

#include "colour.hpp"
#include "globals.hpp"
#include "vec3.hpp"

extern unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][BYTES_PER_PIXEL];

void WriteColour(int x, int y, int width, int height, Colour pixelColour)
{
	double r = pixelColour.x;
	double g = pixelColour.y;
	double b = pixelColour.z;
	double scale = 1.0 / SAMPLES_PER_PIXEL;
	r *= scale;
	g *= scale;
	b *= scale;

	image[x][y][2] = (unsigned char)r;
	image[x][y][1] = (unsigned char)g;
	image[x][y][0] = (unsigned char)b;
}

#endif