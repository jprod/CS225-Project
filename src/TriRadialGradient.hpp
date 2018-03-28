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
    Point randomPoint(int xMax, int yMin) {
        return Point(randDouble() * xMax, randDouble() * yMin);
    }
    // generates a random double between 0 and 1 (inclusive)
    double randDouble() {
        return ((double)rand())/INT_MAX;
    }
    
    public:
    void applyGradient(image<rgb_pixel> &img) {
//        Point rPoint(0,0);
//        Point gPoint(10,10);
//        Point bPoint(100,100);
        
        Point rPoint = randomPoint(img.get_width(), img.get_height());
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
        
        img.set_pixel(rPoint.x, rPoint.y, rgb_pixel(255, 255, 255));
        img.set_pixel(gPoint.x, gPoint.y, rgb_pixel(255, 255, 255));
        img.set_pixel(bPoint.x, bPoint.y, rgb_pixel(255, 255, 255));
    }
    
    
    int furthestDistance(Point p, image<rgb_pixel> &img) {
        Point topL(0, 0);
        Point topR(img.get_width(), 0);
        Point botL(0, img.get_height());
        Point botR(img.get_width(), img.get_height());
        
        int dists[] = {topL - p, topR - p, botL - p, botR - p};
        
        int max = dists[0];
        for (int i = 1; i < 4; i++)
            if (max < dists[i])
                max = dists[i];
        
        return max;
    }
};

#endif // _TRI_RADIAL_GRADIENT_H_
