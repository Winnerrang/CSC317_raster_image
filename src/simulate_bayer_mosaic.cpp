#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  int row = pixel_index / width;
	  int col = pixel_index % width;

	  unsigned char new_pixel;
	  if (row % 2 == 0 && col % 2 == 0) {
		  new_pixel = rgb[pixel_index * 3 + 1];
	  }
	  else if (row % 2 == 0 && col % 2 == 1) {
		  new_pixel = rgb[pixel_index * 3 + 2];
	  }
	  else if (row % 2 == 1 && col % 2 == 0) {
		  new_pixel = rgb[pixel_index * 3];
	  }
	  else {
		  new_pixel = rgb[pixel_index * 3 + 1];
	  }

	  bayer[pixel_index] = new_pixel;
  }
}
