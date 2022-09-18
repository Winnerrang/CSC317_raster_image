#include "over.h"
#define ALPHA 3
void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  std::vector<unsigned char> result(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////

  for (int pixel_index = 0; pixel_index < width * height; pixel_index++) {
	  double alpha_a = (double)A[pixel_index * 4 + ALPHA] / 255.0;
	  double alpha_b = (double)B[pixel_index * 4 + ALPHA] / 255.0;
	  for (int color = 0; color < 3; color++) {
		   //formula is derived from http://ssp.impulsetrain.com/porterduff.html
		   double new_intensity = alpha_a * (double)A[pixel_index * 4 + color] + (1 - alpha_a) * alpha_b * (double)B[pixel_index * 4 + color];
		   if (new_intensity > 255) new_intensity = 255;
		   result[pixel_index * 4 + color] = (unsigned char) new_intensity;
	  }
	  
	  result[pixel_index * 4 + ALPHA] = (unsigned char) (255 * (alpha_a + alpha_b * (1 - alpha_a)));
	  
  }

  C = result;
}
