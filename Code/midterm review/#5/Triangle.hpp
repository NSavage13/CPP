//
//  Triangle.hpp
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
#ifndef Triangle_hpp
#define Triangle_hpp
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
#include <stdio.h>

class Triangle : public Line {
private:
    double x3, y3;
  
public:
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    void setX3(double x3);
    void setY3(double y3);
    double getX3();
    double getY3();
    string toString() override;
    double area();

};

#endif /* Triangle_hpp */
