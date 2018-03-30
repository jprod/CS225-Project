#include <iostream>
#include <sstream>      // std::stringstream
#include <string>
#include <cstdlib> // for rand()
#include <ctime> // for time()
#include "../vendor/png++-0.2.9/png.hpp"
#include "GradientAlgorithm.hpp"
#include "HorizontalGradient.hpp"
#include "TriRadialGradient.hpp"
#include "BezierHorizontalGradient.hpp"
#include "CurveGradient.hpp"

using namespace png;

void getInput(int& varBuf) {
    std::string userVar;
    std::getline (std::cin,userVar);
    if (userVar.find_last_of((std::string)"px") != std::string::npos) {
        userVar = userVar.substr(0,userVar.find_last_of((std::string)"px"));
    }
    if (userVar == "") {
        varBuf = 1000;
    } else {
        std::stringstream ss;
        ss<<userVar;
        ss>>varBuf;
        if (ss.fail()) {
            std::cout << "-Not reconized defaulting to 1000px-" << std::endl;
            ss.clear();
            std::string dummy;
            ss >> dummy;
            varBuf = 1000;
        } else if (varBuf <= 0) {
            std::cout << "-Not reconized defaulting to 1000px-" << std::endl;
            varBuf = 1000;
        }
    }
}

int main() {
    std::cout<<std::endl;
    std::cout<<"-----------------------------------"<<std::endl;
    std::cout<<"xxx*** GRADIENT GENERATOR ++ ***xxx"<<std::endl;
    std::cout<<"-----------------------------------"<<std::endl<<std::endl;
    
    std::cout<<"Please enter width in px"<<std::endl<<" :  ";
    int widthBuf;
    getInput(widthBuf);
    const int width = widthBuf;

    std::cout<<"Please enter height in px"<<std::endl<<" :  ";
    int heightBuf;
    getInput(heightBuf);
    const int height = heightBuf;

    /* Initialize height */
    image<rgba_pixel> img(width, height);
    
    /* Seed the rng */
    srand(time(NULL));

    
    std::cout<<"Please enter"<<std::endl<<"1 for HorizontalGradient"<<std::endl<<"2 for TriRadialGradient"
    <<std::endl<<"3 for BezierHorizontalGradient"<<std::endl<<"4 for CurveGradient"<<std::endl<<" :  ";
    int user;
    std::cin>>user;
    while (! std::cin || user < 1 || user > 4) {
        std::cin.clear(); //clear error flag
        std::cin.ignore(INT_MAX, '\n'); 
        std::cout<<"Error. Try again. ";
        std::cout<<"Enter a number between 1 and 4 (inclusive)"<<std::endl<<" :  ";
        std::cin>>user;
    }
    GradientAlgorithm *algorithm;
    switch(user) {
        case 1: {
            algorithm = new HorizontalGradient();
            break; 
        }
        case 2: {
            algorithm = new TriRadialGradient();
            break; 
        }
        case 3: {
            algorithm = new BezierHorizontalGradient();
            break; 
        }
        case 4: {
            algorithm = new CurveGradient();
            break; 
        }
        default: {
            algorithm = new HorizontalGradient();
            break; 
        }
    }
    algorithm->applyGradient(img);


    // apply some gradient
    // GradientAlgorithm *algorithm;
    // algorithm = new CurveGradient();
    // algorithm->applyGradient(img);

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

    /* Bezier Function */
//    BezierHorizontalGradient algorithm();
//    algorithm.dispColors();

    // TriRadialGradient algorithm;
    
    /* Apply gradient to image */
//    algorithm.applyGradient(img);
    
    // save the image
//    using namespace std;
//    string outputFile;
//    cout << "output file:";
//    cin >> outputFile;
//    img.write(outputFile);

    /* save image */

    std::cout<<"Enter the output file name"<<std::endl<<" :  ";
    std::string outputFile;
    std::cin >> outputFile;
    if (outputFile.find((std::string)".png\n") != std::string::npos) {
    } else if (outputFile.find_last_of((std::string)".") != std::string::npos) {
        outputFile = outputFile.substr(0,outputFile.find_last_of((std::string)".")) + ".png";
    } else {
        outputFile += ".png";
    }
    img.write(outputFile);
    std::cout<<"File saved to $(pwd)/"<< outputFile <<std::endl<<std::endl;
    /* Temp Auto Test PNG */
    // img.write("test1.png");
    
    return 0;
}
