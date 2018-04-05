// DANIEL STRUCK 2018
#ifndef _HORIZONTAL_GRADIENT_H_
#define _HORIZONTAL_GRADIENT_H_

#include "GradientAlgorithm.hpp"
#include "ColorPoint.hpp"


class HorizontalGradient: public GradientAlgorithm {
    ColorPoint colorBuf[2];
    public:
    HorizontalGradient(long long color[2]);
    HorizontalGradient();
    void applyGradient(image<rgba_pixel> &img);
};

#endif // _HORIZONTAL_GRDIENT_H_
