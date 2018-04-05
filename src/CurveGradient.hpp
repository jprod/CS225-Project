// DANIEL STRUCK 2018
#ifndef _CURVE_GRADIENT_H_
#define _CURVE_GRADIENT_H_

#include <cmath>
#include "GradientAlgorithm.hpp"
#include "ColorPoint.hpp"


class CurveGradient: public GradientAlgorithm {
    private:
    ColorPoint colorBuf[2];
    // returns the result of applying a cosine curve to an input
    double applyCos(double x, int height);
    public:
    // calculates a gradient based on distance from a curve
    void applyGradient(image<rgba_pixel> &img);
    CurveGradient(long long color[2]);
};

#endif // _CURVE_GRADIENT_H_
