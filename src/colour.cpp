#ifndef WB_RT_COLOUR_HPP
#define WB_RT_COLOUR_HPP

#include <cmath>

#include "colour.hpp"
#include "globals.hpp"
#include "vec3.hpp"

extern unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][BYTES_PER_PIXEL];

void WriteColour(int x, int y, int width, int height, Colour pixelColour)
{
	double scale = 1.0 / SAMPLES_PER_PIXEL;

	pixelColour = Colour(
		sqrt(pixelColour.x * scale),
		sqrt(pixelColour.y * scale),
		sqrt(pixelColour.z * scale)
	);

	pixelColour *= 255.999;

	image[x][y][2] = (unsigned char)pixelColour.x;
	image[x][y][1] = (unsigned char)pixelColour.y;
	image[x][y][0] = (unsigned char)pixelColour.z;
}

#endif