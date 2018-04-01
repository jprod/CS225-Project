#include "HorizontalGradient.hpp"

void HorizontalGradient::applyGradient(image<rgba_pixel> &img) {
    for (int x = 0; x < (int)img.get_width(); x++) {
        for (int y = 0; y < (int)img.get_height(); y++) {
            double r = 0;
            double g = 255 * x/img.get_width();
            double b = 255 - g;
            double a = 255;
            img.set_pixel(x, y, rgba_pixel(r, g, b, a));
        }
    }
}
