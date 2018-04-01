#include "Point.hpp"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::operator-(Point &other) {
    int xDist = x - other.x;
    int yDist = y - other.y;
    return sqrt(xDist*xDist + yDist*yDist);
}
