#include <iostream>
#include <string>
#include "../vendor/png++-0.2.9/png.hpp"
#include "GradientAlgorithm.h"

using namespace png;

int main() {
    typedef ty
    image<rgb_pixel> img;
    
    // apply some gradient
    
    
    // save the image
    string outputFile;
    cout << "output file:";
    cin >> outputFile;
    img.write(outputFile);
    
    return 0;
}
