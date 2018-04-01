// DANIEL STRUCK 2018
#ifndef _TRI_RADIAL_GRADIENT_H_
#define _TRI_RADIAL_GRADIENT_H_

#include <cstdlib>
#include "GradientAlgorithm.hpp"
#include "Point.hpp"

class TriRadialGradient: public GradientAlgorithm {
    private:
    /* generates a point with a random number from 0
     * to imgWidth for x and from 0 to imgHeight for y
     */
    Point randomPoint(int xMax, int yMin);
    // generates a random double between 0 and 1 (inclusive)
    double randDouble();
    public:
    void applyGradient(image<rgba_pixel> &img);
    
    int furthestDistance(Point p, image<rgba_pixel> &img);
};

#endif // _TRI_RADIAL_GRADIENT_H_
