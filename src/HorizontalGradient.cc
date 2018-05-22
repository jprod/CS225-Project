// JOSHUA RODRIGUEZ 2018
#include "HorizontalGradient.hpp"

void HorizontalGradient::dispColors() {
    std::cout << colorBuf[0].red << colorBuf[0].green << colorBuf[0].blue <<  std::endl;
    std::cout << colorBuf[1].red << colorBuf[1].green << colorBuf[1].blue <<  std::endl;
    std::cout << colorBuf[2].red << colorBuf[2].green << colorBuf[2].blue <<  std::endl;
    std::cout << bezierRecur(0.8, colorBuf, 3) << std::endl;
}

HorizontalGradient::HorizontalGradient(long long color[], int colorLen) {
    for (int i = 0; i < colorLen; i++) {
        /* Apply mask and move bits */
        colorBuf[i].red = (color[i] & ColorPoint::redMask) >> 6*4;
        colorBuf[i].green = (color[i] & ColorPoint::greenMask) >> 4*4;
        colorBuf[i].blue = (color[i] & ColorPoint::blueMask) >> 2*4;
        colorBuf[i].alpha = (color[i] & ColorPoint::alphaMask);
    }
    colorBufLen = colorLen;
}

HorizontalGradient::HorizontalGradient() {
    long long color[4] = {0xFFFFFFE8, 0xAAAA66FF, 0x330033FF, 0x000000E8};
    for (int i = 0; i < 4; i++) {
        /* Apply mask and move bits */
        colorBuf[i].red = (color[i] & ColorPoint::redMask) >> 6*4;
        colorBuf[i].green = (color[i] & ColorPoint::greenMask) >> 4*4;
        colorBuf[i].blue = (color[i] & ColorPoint::blueMask) >> 2*4;
        colorBuf[i].alpha = (color[i] & ColorPoint::alphaMask);
    }
    colorBufLen = 4;
}

void HorizontalGradient::applyGradient(image<rgba_pixel> &img) {
    for (int x = 0; x < (int)img.get_width(); x++) {
        for (int y = 0; y < (int)img.get_height(); y++) {
            double t = (double)x;
            dither(t, x, y);
            t /= img.get_width();
            bindBounds(t);
            ColorPoint bz = bezierRecur(t, colorBuf, colorBufLen);
            img.set_pixel(x, y, rgba_pixel(bz.red, bz.green, bz.blue, bz.alpha));
        }
    }
}
