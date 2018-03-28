#include <iostream>
#include <string>
#include <cstdlib> // for rand()
#include <ctime> // for time()
#include "../vendor/png++-0.2.9/png.hpp"
#include "GradientAlgorithm.hpp"
#include "HorizontalGradient.hpp"
#include "TriRadialGradient.hpp"

using namespace png;

int main() {
    const int width = 500;
    const int height = width;
    
    // seed the rng
    srand(time(NULL));
    
    image<rgb_pixel> img(width, height);
    
    // apply some gradient
//    GradientAlgorithm *algorithm;
//    algorithm = new TriRadialGradient();
//    algorithm->applyGradient(img);
    TriRadialGradient algorithm;
    algorithm.applyGradient(img);
    
    // save the image
    using namespace std;
    string outputFile;
    cout << "output file:";
    cin >> outputFile;
    img.write(outputFile);
    
    return 0;
}
