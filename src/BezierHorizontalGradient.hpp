// JOSHUA RODRIGUEZ 2018
#ifndef _BEZIER_HORIZONTAL_GRADIENT_H_
#define _BEZIER_HORIZONTAL_GRADIENT_H_

#include "GradientAlgorithm.hpp"
#include "ColorPoint.hpp"

template<class T>
T bezierQuad(double t, T p0, T p1, T p2) {
    double nt = (1.0 - t);
    /* Bezier Quadraic Equation */
    return (nt * (nt * p0 + t * p1) + t * (nt * p1 + t * p2));
}

/* Bezier Recursion for n number of Bezier points */
template<class T>
T bezierRecur(double t, T point[], int pointLen) {
    /* When the function can be evalutated in a quadratic way */
    if (pointLen <= 3) {
        return bezierQuad(t, point[0], point[1], point[2]);
    }
    else {
        double nt = (1.0 - t);
        return (nt * bezierRecur(t, point, pointLen - 1) + t * bezierRecur(t, point + 1, pointLen - 1));
    }
}

class BezierHorizontalGradient: public GradientAlgorithm {
private:
    /* Set of Bit Masks for an longlong color alpha notations
    Could be placed elsewhere */
    const long long redMask   = 0xFF000000;
    const long long greenMask = 0x00FF0000;
    const long long blueMask  = 0x0000FF00;
    const long long alphaMask  = 0x000000FF;
    /* A buffer for all the color points */
    ColorPoint colorBuf[20];
    int colorBufLen;
public:
    /* A debug script */
    void dispColors() {
        std::cout << colorBuf[0].red << colorBuf[0].green << colorBuf[0].blue <<  std::endl;
        std::cout << colorBuf[1].red << colorBuf[1].green << colorBuf[1].blue <<  std::endl;
        std::cout << colorBuf[2].red << colorBuf[2].green << colorBuf[2].blue <<  std::endl;
        std::cout << bezierQuad(0.8, colorBuf[0].red, colorBuf[1].red, colorBuf[2].red) << std::endl;
    }
    /* Moving the inputed long longs into the color point buffer */
    BezierHorizontalGradient(long long p0[], int pointLen) {
        for (int i = 0; i < pointLen; i++) {
            colorBuf[i].red = (p0[i] & redMask) >> 6*4;
            colorBuf[i].green = (p0[i] & greenMask) >> 4*4;
            colorBuf[i].blue = (p0[i] & blueMask) >> 2*4;
            colorBuf[i].alpha = (p0[i] & alphaMask);
        }
        colorBufLen = pointLen;
    }
    /* Applying the gradents with the bezier equation */
    void applyGradient(image<rgba_pixel> &img) {
        for (int x = 0; x < img.get_width(); x++) {
            for (int y = 0; y < img.get_height(); y++) {
                double t = ((double)y / img.get_height());
                double r = bezierRecur(t, colorBuf, colorBufLen).red;
                double g = bezierRecur(t, colorBuf, colorBufLen).green;
                double b = bezierRecur(t, colorBuf, colorBufLen).blue;
                double a = bezierRecur(t, colorBuf, colorBufLen).alpha;
                img.set_pixel(x, y, rgba_pixel(r, g, b, a));
            }
        }
    }
};

#endif // _BEZIER_HORIZONTAL_GRDIENT_H_
