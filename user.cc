#include <iostream>
#include <string.h>
#include <cstdlib>
//#include <stdafx.h>
#include "GradientAlgorithm.hpp"
#include "HorizontalGradient.hpp"
#include "TriRadialGradient.hpp"
#include "BezierHorizontalGradient.hpp"

using namespace std;

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
}