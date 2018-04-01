#include "CurveGradient.hpp"

double CurveGradient::applyCos(double x) {
    x /= 100; // horizontal scaling
    return 200.0*cos(x) + 500.0;
}


void CurveGradient::applyGradient(image<rgba_pixel> &img) {
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