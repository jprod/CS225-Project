#ifndef _GRADIENT_ALGORITHM_H_
#define _GRADIENT_ALGORITHM_H_

#include "../vendor/png++-0.2.9/image.hpp"

using namespace png;

template< typename pixel, typename pixel_buffer_type = pixel_buffer< pixel > >
class GradientAlgorithm {
  public:
    virtual void applyGradient(image<pixel, pixel_buffer_type>&) = 0;
};

#endif // _GRADIENT_ALGORITHM_H_
