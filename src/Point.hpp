// DANIEL STRUCK 2018
#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>

class Point {
    public:
    int x, y;

    Point(int x = 0, int y = 0);
    int operator-(Point &other);
};

#endif // _POINT_H_
