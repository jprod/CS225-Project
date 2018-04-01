#ifndef _CURVE_GRADIENT_H_
#define _CURVE_GRADIENT_H_

#include <cmath>
#include "GradientAlgorithm.hpp"

class CurveGradient: public GradientAlgorithm {
    private:
    // returns the result of applying a cosine curve to an input
    double applyCos(double x);
    
    public:
    // calculates a gradient based on distance from a curve
    void applyGradient(image<rgba_pixel> &img);
};

#endif // _CURVE_GRADIENT_H_
