//
//  Line.hpp
//  #5
//
//  Created by Nico Savage on 5/16/23.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;



class Line{
private:
    double x1, y1, x2, y2;
    
    
public:
    Line();
    Line(double x1, double x2, double y1, double y2);
    void setX1(double x1);
    void setX2(double x2);
    void setY1(double y1);
    void setY2(double y2);
    
    
    double getX1();
    double getX2();
    double getY1();
    double getY2();
    
    double getSlope();
    
    virtual string toString();
};

#endif /* Line_hpp */
