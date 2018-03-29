#ifndef _COLOR_POINT_H_
#define _COLOR_POINT_H_

class ColorPoint {
    public:
    double red; 
    double green; 
    double blue; 
    double alpha;

    ColorPoint(double red, double green, double blue, double alpha) {
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->alpha = alpha;
    }
    ColorPoint(){
        red = 0.0;
        green = 0.0;
        blue = 0.0;
        alpha = 0.0;
    }
};

#endif // _COLOR_POINT_H_
