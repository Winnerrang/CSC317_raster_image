#include "rotate.h"
#include <iostream>
void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  int row = pixel_index / width;
	  int col = pixel_index % width;

	  int new_row = -1 * col + width - 1;
	  int new_col = row;
	  int new_pixel_index = new_row * height + new_col;
	  //std::cout << row << " " << col << " " << new_row << " " << new_col << std::endl;
	  for (int channel = 0; channel < num_channels; channel++) {
		  rotated[new_pixel_index * num_channels + channel] = input[pixel_index * num_channels + channel];
	  }
  }
}
