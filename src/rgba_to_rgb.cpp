#include "rgba_to_rgb.h"
#include <iostream>
void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {

	  rgb[3 * pixel_index] = rgba[4 * pixel_index];
	  rgb[3 * pixel_index + 1] = rgba[4 * pixel_index + 1];
	  rgb[3 * pixel_index + 2] = rgba[4 * pixel_index + 2];
  }
}
