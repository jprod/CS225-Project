// JOSHUA RODRIGUEZ 2018
#include "CurveGradient.hpp"


double CurveGradient::applyCos(double x, int height) {
    double period = 500.0;
    double amplitude = 200.0;
    x *= (20)/(period * M_PI); // horizontal scaling
    return amplitude * cos(x) + 0.5 * height;
}

void CurveGradient::applyGradient(image<rgba_pixel> &img) {
    int domain = 100;
    int sampleFq = 6;
    int w = (int)img.get_width();
    int h = (int)img.get_height();
    double fn [w + 2 * domain];
    for (int d = 0; d < 2 * domain + w; d++)
        fn[d] = applyCos(d - domain, h);
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            double distance = abs(fn[x + domain]-y);
            for (int dx = -1 * domain; dx < domain; dx += sampleFq) {
                double _dist = sqrt(dx * dx + pow(fn[dx + x + domain] - y, 2));
                // apply a function
                if (distance > _dist)
                    distance = _dist;
            }
            // find distance from y to yPos, scale to color max, scale to image height
            // std::cout<<distance;
            double t = distance/h;
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
