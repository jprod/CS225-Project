// JOSHUA RODRIGUEZ 2018
#ifndef _COLOR_POINT_H_
#define _COLOR_POINT_H_

/* color point class */
class ColorPoint {
public:
    double red; 
    double green; 
    double blue; 
    double alpha;

    /* Move the parameter into the fields */
    ColorPoint(double red, double green, double blue, double alpha);

    /* Default to 0.0 */
    ColorPoint();

    /* Overload for + operations */
    ColorPoint operator+(ColorPoint cp);

    /* Overload for * operations with a scalar */
    friend ColorPoint operator*(double t, ColorPoint cp);
};

#endif // _COLOR_POINT_H_
