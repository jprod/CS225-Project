#include <iostream>
#include <string>
#include <cstdlib> // for rand()
#include <ctime> // for time()
//#include "../vendor/png++-0.2.9/png.hpp"
#include "GradientAlgorithm.hpp"
#include "HorizontalGradient.hpp"
#include "TriRadialGradient.hpp"
#include "BezierHorizontalGradient.hpp"

using namespace png;

string chooseGradient(int num, string array[]){
	switch(num) {
		case 1:
			return array[1];
		case 2:
			return array[2];
		case 3:
			return array[3];
		case 4: 
			return array[4];
		default:
			return array[1];
	}
}

int main() {
    string choice[5];
	choice[1] = system("GradientAlgorithm.hpp");
	choice[2] = system("HorizontalGradient.hpp");
	choice[3] = system("TriRadialGradient.hpp");
	choice[4] = system("BezierHorizontalGradient.hpp");
	
	int user;
	string gradientChoice;
	cout<<"Please enter"<<endl<<"1 for GradientAlgorithm"<<endl<<"2 for HorizontalGradient"<<endl<<"3 for TriRadialGradient"<<endl<<"4 for BezierHorizontalGradient"<<endl;
	cin>>user;
	gradientChoice = chooseGradient(user,choice);
	//showGraient(gradientChoice);
	const int width = 1000;
    const int height = width;
    
    // seed the rng
    srand(time(NULL));
    
    image<rgba_pixel> img(width, height);
    
    // apply some gradient
//    GradientAlgorithm *algorithm;
//    algorithm = new TriRadialGradient();
//    algorithm->applyGradient(img);

    /* Inputs to the parameters of the bezier funct*/
    long long p0;
    std::cout << "Color Point 0: ";
    std::cin >> std::hex >> p0;
    long long p1;
    std::cout << "Color Point 1: ";
    std::cin >> std::hex >> p1;
    long long p2;
    std::cout << "Color Point 2: ";
    std::cin >> std::hex >> p2;
    long long param[3] = {p0, p1, p2};
    /* Bezier Function */
    BezierHorizontalGradient algorithm(param);
    algorithm.dispColors();

    // TriRadialGradient algorithm;
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