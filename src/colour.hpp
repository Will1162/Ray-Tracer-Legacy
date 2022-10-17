#ifndef WB_RT_COLOUR_HPP
#define WB_RT_COLOUR_HPP

#include "globals.hpp"
#include "vec3.hpp"

extern unsigned char image[IMAGE_HEIGHT][IMAGE_WIDTH][BYTES_PER_PIXEL];

void WriteColour(int x, int y, int width, int height, Colour pixelColour)
{
	image[x][y][2] = (unsigned char) pixelColour.x;
	image[x][y][1] = (unsigned char) pixelColour.y;
	image[x][y][0] = (unsigned char) pixelColour.z;
}

#endif