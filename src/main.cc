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

bool getResolution(int& varBuf);

bool getColor(long long color[], int& colorLen, int colorMin, int colorMax);

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
            widthFlag = getResolution(widthBuf);
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
            heightFlag = getResolution(heightBuf);
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout<<"Error. Try again. ";
        std::cout<<"Enter a number between 1 and 4 (inclusive)"<<std::endl<<" :  ";
        std::cin>>user;
    }
    std::cin.clear(); //clear error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    GradientAlgorithm *algorithm;
    switch(user) {
        case 1: {
            long long color[2] = {0xFFFF00FF, 0x00FFFFFF};
            int colorLen = 2;
            getColor(color, colorLen, 2, 2);
            algorithm = new HorizontalGradient(color);
            break; }
        case 2: {
            algorithm = new TriRadialGradient();
            break; }
        case 3: {
            long long color[20] = {0xFFFFFFE8, 0xAAAA66FF, 0x330033FF, 0x000000E8};
            int colorLen = 4;
            getColor(color, colorLen, 2, 20);
            std::cout<<colorLen;
            algorithm = new BezierHorizontalGradient(color, colorLen);
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

bool getResolution(int& varBuf) {
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

bool getColor(long long color[], int& colorLen, int colorMin, int colorMax) {
    std::string userVar;
    bool contFlag =  true;
    for (int i = 0; contFlag && i < colorMax; i++) {
        if ((i + 1) > colorMin) {
            std::cout << "Enter colors in hex or 'q' when done : ";
        } else 
            std::cout << "Enter colors in hex : ";
        std::getline (std::cin,userVar);
        // std::cout << "GOOD";
        if ((i == 0 || (i + 1) > colorMin) && userVar == "q") {
            contFlag = false;
            // std::cout << " --CONTFLAG FALSE-- ";
        } else {
            std::stringstream ss;
            ss << userVar;
            ss >>  std::hex >> color[i];
            colorLen = i + 1;
            // std::cout << " --INPUT READ AS " << userVar << "-- ";
        }
        // std::cout << " --SAVED-- ";
    }
    return true;
}
