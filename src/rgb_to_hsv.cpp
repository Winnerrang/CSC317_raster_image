#include "rgb_to_hsv.h"
#include <cmath>
#include <vector>
#define RED 0
#define GREEN 1
#define BLUE 2

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  std::vector<double> color(3);
  color[0] = r;
  color[1] = g;
  color[2] = b;

  double M, m, c;
  int max_color;
  if (r >= g && r >= b) max_color = RED;
  else if (g >= r && g >= b) max_color = GREEN;
  else max_color = BLUE;
  M = color[max_color];

  m = std::fmin(r, std::fmin(g, b));

  c = M - m;

  v = M;
  if (v == 0) {
	  s = 0;
  }
  else {
	  s = (M - m) / v;
  }
  
  if (c == 0) h = NAN;
  else {
	  h = (color[(max_color + 1) % 3] - color[(max_color + 2) % 3]) / c + 2 * (max_color);
	  if (h < 0) h += 6;
	  h *= 60;
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
