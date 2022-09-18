#include "demosaic.h"
#include <iostream>
#include <cassert>
int check_color(int row, int col);
bool check_boundary(int row, int col, int width, int height);

#define RED 0;
#define GREEN 1;
#define BLUE 2;

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  
  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  int row = pixel_index / width;
	  int col = pixel_index % width;
	  int self_color = check_color(row, col);

	  for (int color = 0; color < 3; color++) {
		  unsigned char pixel_color;
		  if (color == self_color) {
			  pixel_color = bayer[pixel_index];
		  }
		  else {
			  int count = 0;
			  int sum = 0;
			  for (int dx = -1; dx <= 1; dx++) {
				  for (int dy = -1; dy <= 1; dy++) {
					  int new_row = row + dy;
					  int new_col = col + dx;
					  if (dx == 0 && dy == 0) continue;
					  if (!check_boundary(new_row, new_col, width, height)) {
						  continue;
					  }

					  if (check_color(new_row, new_col) == color) {
						  count++;
						  sum += (int)bayer[new_row * width + new_col];
					  }
				  }
			  }

			  assert(count != 0);
			  pixel_color = (unsigned char)(sum / count);
			  
		  }

		  rgb[pixel_index * 3 + color] = pixel_color;
	  }

  }

}

int check_color(int row, int col) {
	if (row % 2 == 0 && col % 2 == 0) {
		return GREEN;
	}
	else if (row % 2 == 0 && col % 2 == 1) {
		return BLUE;
	}
	else if (row % 2 == 1 && col % 2 == 0) {
		return RED;
	}
	else {
		return GREEN;
	}
}

bool check_boundary(int row, int col, int width, int height) {
	if (row < 0 || row >= height) {
		return false;
	}

	if (col < 0 || col >= width) {
		return false;
	}

	return true;
	
}