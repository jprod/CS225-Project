// ANDREW STRICKLER 2018
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

bool getInput(int& varBuf);

int main() {
    std::cout<<std::endl;
    std::cout<<"-----------------------------------"<<std::endl;
    std::cout<<"xxx*** GRADIENT GENERATOR ++ ***xxx"<<std::endl;
    std::cout<<"-----------------------------------"<<std::endl<<std::endl;
    
    /* Reading inputs for the image width */
    std::cout<<"Please enter image width in px (or press enter for default 1000px)"<<std::endl<<" :  ";
    int widthBuf;
    bool widthFlag = true;
    do {
        try {
            widthFlag = getInput(widthBuf);
        }
        catch(const std::invalid_argument& ERROR_MSG) {
            std::cout<<ERROR_MSG.what()<<std::endl;
            std::cout<<"Please re-enter width in px"<<std::endl<<" :  ";
            widthFlag = false;
        }
    } while (!widthFlag);
    const int width = widthBuf;

    /* Reading inputs for the image height */
    std::cout<<"Please enter image height in px (or press enter for default 1000px)"<<std::endl<<" :  ";
    int heightBuf;
    bool heightFlag = true;
    do {
        try {
            heightFlag = getInput(heightBuf);
        }
        catch(const std::invalid_argument& ERROR_MSG) {
            std::cout<<ERROR_MSG.what()<<std::endl;
            std::cout<<"Please re-enter height in px"<<std::endl<<" :  ";
            heightFlag = false;
        }
    } while (!heightFlag);
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

bool getInput(int& varBuf) {
    std::string userVar;
    std::getline (std::cin,userVar);
    if (userVar.rfind(std::string("px")) != std::string::npos) {
        userVar = userVar.substr(0,userVar.rfind(std::string("px")));
    }
    if (userVar == "") {
        // std::cout<<"IM AT POINT 1   ";
        varBuf = 1000;
        return true;
    } else {
        std::stringstream ss;
        ss<<userVar;
        ss>>varBuf;
        if (ss.fail()) {
            ss.clear();
            std::string dummy;
            ss >> dummy;
            throw std::invalid_argument("-Invalid  Input-");
        } else if (varBuf <= 0) {
            throw std::invalid_argument("-Invalid Number-");
        }
        // std::cout<<"IM AT POINT 2   ";
        return true;
    }
}
