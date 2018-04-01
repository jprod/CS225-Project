#include "ColorPoint.hpp"

ColorPoint::ColorPoint(double red, double green, double blue, double alpha) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

ColorPoint::ColorPoint() {
    red = 0.0;
    green = 0.0;
    blue = 0.0;
    alpha = 0.0;
}

ColorPoint ColorPoint::operator+(ColorPoint cp) {
    ColorPoint temp;
    temp.red = this->red + cp.red;
    temp.green = this->green + cp.green;
    temp.blue = this->blue + cp.blue;
    temp.alpha = this->alpha + cp.alpha;
    return temp;
}

ColorPoint operator*(double t, ColorPoint cp) {
    ColorPoint temp;
    temp.red = t * cp.red;
    temp.green = t * cp.green;
    temp.blue = t * cp.blue;
    temp.alpha = t * cp.alpha;
    return temp;
}