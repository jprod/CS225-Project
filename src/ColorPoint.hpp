// JOSHUA RODRIGUEZ 2018
#ifndef _COLOR_POINT_H_
#define _COLOR_POINT_H_

#include <iostream>

/* color point class */
class ColorPoint {
public:
    /* Set of Bit Masks for a longlong color alpha notations */
    static long long redMask;
    static long long greenMask;
    static long long blueMask;
    static long long alphaMask;
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

    /* Overload for << operations with a scalar */
    friend std::ostream& operator<<(std::ostream& os, const ColorPoint& cp);

};

#endif // _COLOR_POINT_H_
