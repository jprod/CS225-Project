// JOSHUA RODRIGUEZ 2018
#include "CurveGradient.hpp"


double CurveGradient::applyCos(double x, int height) {
    double horizontalScale = 100.0;
    double verticalScale = 200.0;
    x /= horizontalScale; // horizontal scaling
    return verticalScale * cos(x) + 0.5 * height;
}

void CurveGradient::applyGradient(image<rgba_pixel> &img) {
    for (int x = 0; x < (int)img.get_width(); x++) {
        // apply a function
        double fnx = applyCos(x, (int)img.get_height());
        for (int y = 0; y < (int)img.get_height(); y++) {
            // find distance from y to yPos, scale to color max, scale to image height
            double t = abs((double)y - fnx)/img.get_height();
            // apply gradient
            ColorPoint cg = linearGrad(t, colorBuf);
            img.set_pixel(x, y, rgba_pixel(cg.red, cg.green, cg.blue, cg.alpha));
        }
    }
}

CurveGradient::CurveGradient(long long color[2]) {
    for (int i = 0; i < 2; i++) {
        /* Apply mask and move bits */
        colorBuf[i].red = (color[i] & ColorPoint::redMask) >> 6*4;
        colorBuf[i].green = (color[i] & ColorPoint::greenMask) >> 4*4;
        colorBuf[i].blue = (color[i] & ColorPoint::blueMask) >> 2*4;
        colorBuf[i].alpha = (color[i] & ColorPoint::alphaMask);
    }
}
