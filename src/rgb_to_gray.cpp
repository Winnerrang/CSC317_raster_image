#include "rgb_to_gray.h"
#include <cmath>
void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  float R, G, B, gray_scale;
	  R = (float)rgb[3 * pixel_index] / 255;
	  G = (float)rgb[3 * pixel_index + 1] / 255;
	  B = (float)rgb[3 * pixel_index + 2] / 255;
	  
	  gray_scale = 0.2126f * R + 0.7152f * G + 0.0722f * B;
	  gray[pixel_index] = (char)round(gray_scale * 255);
  }
}


