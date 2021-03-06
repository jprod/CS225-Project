// JOSHUA RODRIGUEZ 2018
#ifndef _HORIZONTAL_GRADIENT_H_
#define _HORIZONTAL_GRADIENT_H_

#include "GradientAlgorithm.hpp"
#include "ColorPoint.hpp"

class HorizontalGradient: public GradientAlgorithm {
private:
    /* A buffer for all the color points */
    ColorPoint colorBuf[20];
    int colorBufLen;
public:
    /* A debug script */
    void dispColors();
    /* Moving the inputed long longs into the color point buffer */
    HorizontalGradient(long long color[], int colorLen);
    HorizontalGradient();
    /* Applying the gradents with the bezier equation 
        also applys dither to the gradient */
    void applyGradient(image<rgba_pixel> &img);
};

#endif // _BEZIER_HORIZONTAL_GRDIENT_H_
