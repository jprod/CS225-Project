// DANIEL STRUCK 2018
#include "HorizontalGradient.hpp"

void HorizontalGradient::applyGradient(image<rgba_pixel> &img) {
    for (int x = 0; x < (int)img.get_width(); x++) {
        for (int y = 0; y < (int)img.get_height(); y++) {
            double t = (double)x;
            t /= img.get_width();
            ColorPoint hg = linearGrad(t, colorBuf);
            img.set_pixel(x, y, rgba_pixel(hg.red, hg.green, hg.blue, hg.alpha));
        }
    }
}

HorizontalGradient::HorizontalGradient(long long color[2]) {
    for (int i = 0; i < 2; i++) {
        /* Apply mask and move bits */
        colorBuf[i].red = (color[i] & ColorPoint::redMask) >> 6*4;
        colorBuf[i].green = (color[i] & ColorPoint::greenMask) >> 4*4;
        colorBuf[i].blue = (color[i] & ColorPoint::blueMask) >> 2*4;
        colorBuf[i].alpha = (color[i] & ColorPoint::alphaMask);
    }
}

HorizontalGradient::HorizontalGradient() {
    long long color[2] = {0x00FF00FF, 0x0000FFFF};
    for (int i = 0; i < 2; i++) {
        /* Apply mask and move bits */
        colorBuf[i].red = (color[i] & ColorPoint::redMask) >> 6*4;
        colorBuf[i].green = (color[i] & ColorPoint::greenMask) >> 4*4;
        colorBuf[i].blue = (color[i] & ColorPoint::blueMask) >> 2*4;
        colorBuf[i].alpha = (color[i] & ColorPoint::alphaMask);
    }
}