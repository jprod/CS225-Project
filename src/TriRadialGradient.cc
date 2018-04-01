#include "TriRadialGradient.hpp"

Point TriRadialGradient::randomPoint(int xMax, int yMin) {
    return Point(randDouble() * xMax, randDouble() * yMin);
}

double TriRadialGradient::randDouble() {
    return ((double)rand())/INT_MAX;
}

void TriRadialGradient::applyGradient(image<rgba_pixel> &img) {
   // Point rPoint(0,0);
   // Point gPoint(10,10);
   // Point bPoint(100,100);
    
    Point rPoint = randomPoint(img.get_width(), img.get_height());
    Point gPoint = randomPoint(img.get_width(), img.get_height());
    Point bPoint = randomPoint(img.get_width(), img.get_height());
    
    int farR = furthestDistance(rPoint, img);
    int farG = furthestDistance(gPoint, img);
    int farB = furthestDistance(bPoint, img);
    
    for (int x = 0; x < (int)img.get_width(); x++) {
        for (int y = 0; y < (int)img.get_height(); y++) {
            Point current(x, y);
            double r = 255*(current - rPoint)/farR;
            double g = 255*(current - gPoint)/farG;
            double b = 255*(current - bPoint)/farB;
            img.set_pixel(x, y, rgba_pixel(r, g, b, 255));
        }
    }
    
    img.set_pixel(rPoint.x, rPoint.y, rgba_pixel(255, 255, 255, 255));
    img.set_pixel(gPoint.x, gPoint.y, rgba_pixel(255, 255, 255, 255));
    img.set_pixel(bPoint.x, bPoint.y, rgba_pixel(255, 255, 255, 255));
}

int TriRadialGradient::furthestDistance(Point p, image<rgba_pixel> &img) {
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
