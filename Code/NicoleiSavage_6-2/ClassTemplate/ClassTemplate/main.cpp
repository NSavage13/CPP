//
//  main.cpp
//  ClassTemplate
//
//  Created by Nico Savage on 5/24/23.
/*
 Write a C++ template class called directions that holds two parameters, stepNum, and direction. StepNum is an integer counter. Direction can be of any data type. Create the normal setters, getters, ructors…

 Call in a main using several different datatypes, including one of your custom classes.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

template<class StepType, class DirectionType>
class Directions {
private:
    StepType stepNum;
    DirectionType direction;
    
public:
    Directions() : stepNum(0), direction() {}
    Directions(StepType step, DirectionType dir) : stepNum(static_cast<int>(step)), direction(dir) {}
    
    void setStepNum(StepType step) {stepNum = static_cast<int>(step);}
    
    StepType getStepNum(){
        return static_cast<int>(stepNum);
    }
    void setDirection(DirectionType dir) {direction = dir;}
    DirectionType getDirection() {return direction;}};

class CustomClass {
private:
    int value;

public:
    CustomClass() : value(0) {}
    CustomClass(int val) : value(val) {}
    int getValue()  {return value;}};

int main() {

    Directions d1(5, 'N');
    cout << "Step: " << d1.getStepNum() << ", Direction: " << d1.getDirection() << endl;

    Directions d2(2.5, "East");
    cout << "Step: " << d2.getStepNum() << ", Direction: " << d2.getDirection() << endl;

    CustomClass cc(10);
    Directions<int, CustomClass> d3(3, cc);
    cout << "Step: " << d3.getStepNum() << ", Direction: " << d3.getDirection().getValue() << endl;

    return 0;
}

