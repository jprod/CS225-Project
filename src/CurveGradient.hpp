#ifndef _CURVE_GRADIENT_H_
#define _CURVE_GRADIENT_H_

#include <cmath>
#include "GradientAlgorithm.hpp"

class CurveGradient: public GradientAlgorithm {
    private:
    // returns the result of applying a cosine curve to an input
    double applyCos(double x) {
        x /= 100; // horizontal scaling
        return 200.0*cos(x) + 500.0;
    }
    
    public:
    // calculates a gradient based on distance from a curve
    void applyGradient(image<rgba_pixel> &img) {
        for (int x = 0; x < (int)img.get_width(); x++) {
            // apply a function
            int yVal = applyCos(x);
            for (int y = 0; y < (int)img.get_height(); y++) {
                // find distance from y to yPos, scale to color max, scale to image height
                const double val = 255.0*abs(y - yVal)/img.get_height();
                // apply blue gradient
                img.set_pixel(x, y, rgba_pixel(0, 0, 255-val, 255));
            }
        }
    }
};

#endif // _CURVE_GRADIENT_H_
