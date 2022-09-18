#include "hsv_to_rgb.h"
#include <vector>
#include <cmath>
#include <assert.h>

#define RED 0
#define GREEN 1
#define BLUE 2

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  if (isnan(h)) {
	  r = v;
	  g = v;
	  b = v;
	  return;
  }

  double h_decimal = h - (int)h;
  double h_ = (int)h % 360 + h_decimal;



  std::vector<double> color(3, -1);
  r = 0;
  g = 0;
  b = 0;
  double M, m, c;
  int max_color = (int)((h_ + 60) / 120) % 3;
  int min_color = (int)((h_ + 60 + 180) / 120) % 3;
  int last_color = 3 - (min_color + max_color);
  M = v;
  m = (1 - s) * M;
  c = M - m;
  color[max_color] = M;
  color[min_color] = m;
  
  
  double temp = h_ / 60 - (2 * max_color);

  //special situation when h is between 300 and 0 degree
  if (temp > 1) temp -= 6;
  double diff = temp * c;
  color[last_color] = color[min_color] + std::fabs(diff);


  for (int i = 0; i < 3; i++) {
	  assert(color[i] >= 0);
  }

  r = color[RED];
  g = color[GREEN];
  b = color[BLUE];
}
