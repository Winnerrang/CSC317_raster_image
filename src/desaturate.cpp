#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  double r, g, b, h, s, v;
	  r = rgb[pixel_index * 3] / 255.0;
	  g = rgb[pixel_index * 3 + 1] / 255.0;
	  b = rgb[pixel_index * 3 + 2] / 255.0;

	  rgb_to_hsv(r, g, b, h, s, v);
	  s *= (1 - factor);
	  if (s < 0) s = 0;


	  hsv_to_rgb(h, s, v, r, g, b);


	  desaturated[pixel_index * 3] = (unsigned char)(r * 255);
	  desaturated[pixel_index * 3 + 1] = (unsigned char)(g * 255);
	  desaturated[pixel_index * 3 + 2] = (unsigned char)(b * 255);

  }
}
