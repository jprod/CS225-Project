// JOSHUA RODRIGUEZ 2018
#include "BezierHorizontalGradient.hpp"

double dither(double &t, int x, int y) {
    int ditherLvl = 2;
    for (int i = 1; i < ditherLvl; i ++) {
    ((y % (i+1) && x % (i+1)) || (!(y % (i+1)) && !(x % (i+1)))) ?
                        t += i : t -= i;
    }
    return t;
}

double ditherConstant(double &t, int x, int y) {
    int ditherLvl = 2;
    for (int i = 1; i < ditherLvl; i ++) {
    ((y % (i+1) && x % (i+1)) || (!(y % (i+1)) && !(x % (i+1)))) ?
                        t += 1 : t -= 1;
    }
    return t;
}

double bindBounds(double &t) {
    if (t > 1) 
        t = 1;
    else if (t < 0) 
        t = 0;
    return t;
}

template<class T>
T bezierLinear(double t, T point[]) {
    double nt = (1.0 - t);
    /* Bezier Quadraic Formula */
    return (nt * point[0] + t * point[1]);
}

template<class T>
T bezierQuad(double t, T point[]) {
    double nt = (1.0 - t);
    /* Bezier Quadraic Formula */
    return (nt * (nt * point[0] + t * point[1]) + t * (nt * point[1] + t * point[2]));
}

template<class T>
T bezierRecur(double t, T point[], int pointLen) {
    /* When the function can be evalutated in a quadratic way 
        Or recurse with formula*/
    if (pointLen <= 2) {
        return bezierLinear(t, point);
    } else {
        double nt = (1.0 - t);
        return (nt * bezierRecur(t, point, pointLen - 1) + t * bezierRecur(t, point + 1, pointLen - 1));
    }
}

void BezierHorizontalGradient::dispColors() {
    std::cout << colorBuf[0].red << colorBuf[0].green << colorBuf[0].blue <<  std::endl;
    std::cout << colorBuf[1].red << colorBuf[1].green << colorBuf[1].blue <<  std::endl;
    std::cout << colorBuf[2].red << colorBuf[2].green << colorBuf[2].blue <<  std::endl;
    std::cout << bezierQuad(0.8, colorBuf) << std::endl;
}

BezierHorizontalGradient::BezierHorizontalGradient(long long color[], int colorLen) {
    for (int i = 0; i < colorLen; i++) {
        /* Apply mask and move bits */
        colorBuf[i].red = (color[i] & ColorPoint::redMask) >> 6*4;
        colorBuf[i].green = (color[i] & ColorPoint::greenMask) >> 4*4;
        colorBuf[i].blue = (color[i] & ColorPoint::blueMask) >> 2*4;
        colorBuf[i].alpha = (color[i] & ColorPoint::alphaMask);
    }
    colorBufLen = colorLen;
}

BezierHorizontalGradient::BezierHorizontalGradient() {
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

void BezierHorizontalGradient::applyGradient(image<rgba_pixel> &img) {
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
