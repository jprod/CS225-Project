// DANIEL STRUCK 2018
#ifndef _GRADIENT_ALGORITHM_H_
#define _GRADIENT_ALGORITHM_H_

#include "../vendor/png++-0.2.9/image.hpp"

using namespace png;

double dither(double &t, int x, int y);

double ditherConstant(double &t, int x, int y);

double bindBounds(double &t);

class GradientAlgorithm {
  public:
    virtual void applyGradient(image<rgba_pixel>&) = 0;
};

#endif // _GRADIENT_ALGORITHM_H_
