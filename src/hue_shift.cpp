#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <iostream>
#include <assert.h>
void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  double r, g, b, h, s, v;
	  r = rgb[pixel_index * 3] / 255.0;
	  g = rgb[pixel_index * 3 + 1] / 255.0;
	  b = rgb[pixel_index * 3 + 2] / 255.0;

	  rgb_to_hsv(r, g, b, h, s, v);
	  h += shift;
	  hsv_to_rgb(h, s, v, r, g, b);


	  shifted[pixel_index * 3] = (unsigned char)(r * 255);
	  shifted[pixel_index * 3 + 1] = (unsigned char)(g * 255);
	  shifted[pixel_index * 3 + 2] = (unsigned char)(b * 255);

  }
}
