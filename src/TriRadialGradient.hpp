#ifndef _TRI_RADIAL_GRADIENT_H_
#define _TRI_RADIAL_GRADIENT_H_

#include <cstdlib>
#include <algorithm>    // std::max_element
#include "GradientAlgorithm.hpp"
#include "Point.hpp"

class TriRadialGradient: public GradientAlgorithm {
    private:
    /* generates a point with a random number from 0
     * to imgWidth for x and from 0 to imgHeight for y
     */
    Point randomPoint(int imgWidth, int imgHeight) {
        Point p(rand() * imgWidth, rand() * imgHeight);
        return p;
    }
    
    public:
    void applyGradient(image<rgb_pixel> &img) {
        Point rPoint(0,0);// = randomPoint(img.get_width(), img.get_height());
        Point gPoint = randomPoint(img.get_width(), img.get_height());
        Point bPoint = randomPoint(img.get_width(), img.get_height());
        
        int farR = furthestDistance(rPoint, img);
        int farG = furthestDistance(gPoint, img);
        int farB = furthestDistance(bPoint, img);
        
        for (int x = 0; x < img.get_width(); x++) {
            for (int y = 0; y < img.get_height(); y++) {
                Point current(x, y);
                double r = 255*(current - rPoint)/farR;
                double g = 255*(current - gPoint)/farG;
                double b = 255*(current - bPoint)/farB;
                img.set_pixel(x, y, rgb_pixel(r, g, b));
            }
        }
    }
    
    
    int furthestDistance(Point p, image<rgb_pixel> &img) {
        Point topL(0, 0);
        Point topR(img.get_width(), 0);
        Point botL(0, img.get_height());
        Point botR(img.get_width(), img.get_height());
        
        int dists[] = {topL - p, topR - p, botL - p, botR - p};
        
        return std::max(
    }
};

#endif // _TRI_RADIAL_GRADIENT_H_
