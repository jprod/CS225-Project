#include <iostream>
#include <string>
#include <cstdlib> // for rand()
#include <ctime> // for time()
#include "../vendor/png++-0.2.9/png.hpp"
#include "GradientAlgorithm.hpp"
#include "HorizontalGradient.hpp"
#include "TriRadialGradient.hpp"
#include "BezierHorizontalGradient.hpp"

using namespace png;

int main() {
    const int width = 1000;
    const int height = width;
    
    // seed the rng
    srand(time(NULL));
    
    image<rgba_pixel> img(width, height);
    
    // apply some gradient
//    GradientAlgorithm *algorithm;
//    algorithm = new TriRadialGradient();
//    algorithm->applyGradient(img);

    /* Inputs to the parameters of the bezier funct */
    // long long p0;
    // std::cout << "Color Point 0: ";
    // std::cin >> std::hex >> p0;
    // long long p1;
    // std::cout << "Color Point 1: ";
    // std::cin >> std::hex >> p1;
    // long long p2;
    // std::cout << "Color Point 2: ";
    // std::cin >> std::hex >> p2;
    // long long param[20] = {p0, p1, p2};
    // int paramLen = 3;

    /* Hardcoded bezier parameters */
    long long param[20] = {0xd76969FF, 0x42d5ebFF, 0xedbd2dFF, 0x99AA11F0};
    int paramLen = 4;

    /* Bezier Function */
    BezierHorizontalGradient algorithm(param, paramLen);
    algorithm.dispColors();

    // TriRadialGradient algorithm;
    
    /* Apply gradient to image */
    algorithm.applyGradient(img);
    
    // save the image
    using namespace std;
    // string outputFile;
    // cout << "output file:";
    // cin >> outputFile;
    // img.write(outputFile);

    /* Temp Auto Test PNG */
    img.write("test1.png");
    
    return 0;
}
