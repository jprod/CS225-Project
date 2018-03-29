#ifndef _CURVE_GRADIENT_H_
#define _CURVE_GRADIENT_H_

#include "GradientAlgorithm.hpp"

class CurveGradient: public GradientAlgorithm {
    private:
    // returns the result of applying a quadratic to an input
    int applyQuad(int x) {
        return x*x;
    }
    public:
    // calculates a gradient based on distance from a curve
    void applyGradient(image<rgba_pixel> &img) {
        for (int x = 0; x < img.get_width(); x++) {
            int yVal = applyQuad(x);
            for (int y = 0; y < img.get_height(); y++) {
                img.set_pixel(x, y, rgba_pixel(0, 0, y - yVal, 255));
            }
        }
    }
};

#endif // _CURVE_GRADIENT_H_
