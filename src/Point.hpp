#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>

class Point {
    public:
    int x, y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point(){
        x = 0;
        y = 0;
    }

    int operator-(Point &other) {
        int xDist = x - other.x;
        int yDist = y - other.y;
        return sqrt(xDist*xDist + yDist*yDist);
    }
};

#endif // _POINT_H_
