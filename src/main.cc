#include <iostream>
#include <string>
#include "../vendor/png++-0.2.9/png.hpp"
#include "GradientAlgorithm.hpp"
#include "HorizontalGradient.hpp"

using namespace png;

int main() {
    const int width = 500;
    const int height = width;
    
    image<rgb_pixel> img(width, height);
    
    // apply some gradient
    HorizontalGradient hg;
    hg.applyGradient(img);
    
    // save the image
    using namespace std;
    string outputFile;
    cout << "output file:";
    cin >> outputFile;
    img.write(outputFile);
    
    return 0;
}
