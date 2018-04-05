#include "GradientAlgorithm.hpp"

double dither(double &t, int x, int y) {
    int ditherLvl = 2;
    for (int i = 1; i < ditherLvl; i ++) {
    ((y % (i+1) && x % (i+1)) || (!(y % (i+1)) && !(x % (i+1)))) ?
                        t += i : t -= i;
    }
    return t;
}

double ditherConstant(double &t, int x, int y) {
    int ditherLvl = 2;
    for (int i = 1; i < ditherLvl; i ++) {
    ((y % (i+1) && x % (i+1)) || (!(y % (i+1)) && !(x % (i+1)))) ?
                        t += 1 : t -= 1;
    }
    return t;
}

double bindBounds(double &t) {
    if (t > 1) 
        t = 1;
    else if (t < 0) 
        t = 0;
    return t;
}

