#ifndef _GRADIENT_ALGORITHM_H_
#define _GRADIENT_ALGORITHM_H_

#include "../vendor/png++-0.2.9/image.hpp"

using namespace png;

class GradientAlgorithm {
  public:
    virtual void applyGradient(image<rgb_pixel>&) = 0;
};

#endif // _GRADIENT_ALGORITHM_H_
