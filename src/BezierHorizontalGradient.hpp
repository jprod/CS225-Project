// JOSHUA RODRIGUEZ 2018
#ifndef _BEZIER_HORIZONTAL_GRADIENT_H_
#define _BEZIER_HORIZONTAL_GRADIENT_H_

#include "GradientAlgorithm.hpp"
#include "ColorPoint.hpp"

/* Dither function for smoother gradient */
double dither(double &t, int x, int y);

double ditherConstant(double &t, int x, int y);

/* Binds t if it goes out of range */
double bindBounds(double &t);

/* Bezier Quadratic implementation; three points */
template<class T>
T bezierQuad(double t, T p0, T p1, T p2);

/* Bezier Recursion for n number of Bezier points */
template<class T>
T bezierRecur(double t, T point[], int pointLen);

class BezierHorizontalGradient: public GradientAlgorithm {
private:
    /* Set of Bit Masks for a longlong color alpha notations */
    static long long redMask;
    static long long greenMask;
    static long long blueMask;
    static long long alphaMask;
    /* A buffer for all the color points */
    ColorPoint colorBuf[20];
    int colorBufLen;
public:
    /* A debug script */
    void dispColors();
    /* Moving the inputed long longs into the color point buffer */
    BezierHorizontalGradient(long long p0[], int pointLen);
    BezierHorizontalGradient();
    /* Applying the gradents with the bezier equation 
        also applys dither to the gradient */
    void applyGradient(image<rgba_pixel> &img);
};

#endif // _BEZIER_HORIZONTAL_GRDIENT_H_
