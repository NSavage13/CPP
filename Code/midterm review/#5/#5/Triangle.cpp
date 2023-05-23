//
//  Triangle.cpp
//  #5
//
//  Created by Nico Savage on 5/17/23.
/*
 Build a class called Triangle that inherits from Line. Recall that geometry defines Triangle as a shape with three points.
 Double x3, y3.
 Build
 both constructors
 all setters/getters
 to_string
 Uses the parent constructor
 Function that calculates area
 Area  = |1/2(x1(y2-y3)+x2(y3-y1)+x3(y1-y2))|
 The vertical lines represent absolute value. Math.abs()
 */
#include "Line.hpp"
#include "Triangle.hpp"
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Triangle::Triangle() : Line(){
    x3 = 0;
    y3 = 0;
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : Line(x1,x2,y1,y2){
    this->x3 = x3;
    this->y3 = y3;
}
void Triangle::setX3(double x3){
    this->x3 = x3;
}
void Triangle::setY3(double y3){
    this->y3 = y3;
}
double Triangle::getX3(){
    return x3;
}
double Triangle::getY3(){
    return y3;
}
double Triangle::area(){
    double area = abs(0.5 * (getX1() * (getY2() - getY3()) + getX2() * (getY3() - getY1()) + getX3() * (getY1() - getY2())));
    return area;
}

string Triangle::toString() {
    stringstream ss;
    ss << fixed << setprecision(1);
    ss << "Point 1: (" << getX1() << ", " << getY1() << ")" << endl;
    ss << "Point 2: (" << getX2() << ", " << getY2() << ")" << endl;
    ss << "Point 3: (" << x3 << ", " << y3 << ")" << endl;
    ss << "Area: " << area() << endl;
    return ss.str();
}

