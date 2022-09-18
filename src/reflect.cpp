#include "reflect.h"
#include <iostream>
void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  int row = pixel_index / width;
	  int col = pixel_index % width;
	  
	  int new_row = row;
	  int new_col = width - col - 1;
	  int new_pixel_index = new_row * width + new_col;
	  for (int channel = 0; channel < num_channels; channel++) {
		  reflected[new_pixel_index * num_channels + channel] = input[pixel_index * num_channels + channel];
	  }
  }
}
