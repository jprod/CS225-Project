#ifndef _HORIZONTAL_GRADIENT_H_
#define _HORIZONTAL_GRADIENT_H_

#include "GradientAlgorithm.hpp"

class HorizontalGradient: public GradientAlgorithm {
    public:
    void applyGradient(image<rgba_pixel> &img);
};

#endif // _HORIZONTAL_GRDIENT_H_
