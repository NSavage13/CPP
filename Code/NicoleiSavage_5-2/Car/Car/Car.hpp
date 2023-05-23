//
//  car.hpp
//  5-1
//
//  Created by Nico Savage on 5/9/23.
//

#ifndef Car_hpp
#define Car_hpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;


class Car{
public:
    Car();
    
    Car(string make,string model,int year,double miles,double gallons,double mpg);
    
    string getMake();
    string getModel();
    int getYear();
    double getMiles();
    double getGallons();
    double getMpg();
    double getDistance();
    double getCost();
    
    void setMake(string make);
    void setModel(string model);
    void setYear(int year);
    void setMiles(double miles);
    void setGallons(double gallons);
    void setMpg(double mpg);
    
    string to_string();
    
    friend ostream& operator<<(ostream& os, Car& car);
    friend istream& operator>>(istream& is, Car& car);
    
    bool operator<(Car& c);
    bool operator>(Car& c);
    bool operator==(Car& c);
    bool operator!=(Car& c);
    bool operator<=(Car& c);
    bool operator>=(Car& c);
    
    Car operator+(Car& c);
    Car operator-(Car& c);
    Car operator*(Car& c);
    Car operator/(Car& c);
    Car operator++();
    Car operator++(int);
    
    
protected:
    string make,model;
    int year;
    double miles, gallons, mpg;
};

#endif
