//
//  Line.cpp
//  #5
//
//  Created by Nico Savage on 5/16/23.
//

#include "Line.hpp"
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


Line::Line() : x1(0), y1(0), x2(0), y2(0) {}
Line::Line(double x1, double x2, double y1, double y2) {
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
}

double Line::getX1(){
    return x1;
}
double Line::getX2(){
    return x2;
}
double Line::getY1(){
    return y1;
}
double Line::getY2(){
    return y2;
}
void Line::setX1(double x1){
    this->x1=x1;
}
void Line::setX2(double x2){
    this->x2=x2;
}
void Line::setY1(double y1){
    this->y1=y1;
}
void Line::setY2(double y2){
    this->y2=y2;
}
double Line::getSlope(){
    if(x1 == x2){
        //cerr << "Slope is undefined" << endl;
        return 0;
    }else{
        return (y1-y2)/(x1-x2);
    }
}

string Line::toString(){
    stringstream ss;
    ss << fixed << setprecision(1);
    ss << "Point 1: (" << x1 << ", " << y1 << ")" << endl;
    ss << "Point 2: (" << x2 << ", " << y2 << ")" << endl;
    
    double slope = getSlope();
    if (slope == 0) {
        ss << "Slope: Undefined" << endl;
    } else {
        ss << "Slope: " << slope << endl;
    }
    
    return ss.str();
}




 
    


