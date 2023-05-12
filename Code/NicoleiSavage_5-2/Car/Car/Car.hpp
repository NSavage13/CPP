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

using namespace std;


class Car{
public:
    Car();
    
    Car(string make,string model,int year,double miles,double gallons,double mpg);
    
    string getMake() const;
    string getModel() const;
    int getYear() const;
    double getMiles() const;
    double getGallons() const;
    double getMpg() const;
    double getDistance() const;
    double getCost() const;
    
    void setMake(string make);
    void setModel(string model);
    void setYear(int year);
    void setMiles(double miles);
    void setGallons(double gallons);
    void setMpg(double mpg);
    
    string to_string() const;
    
private:
    string make,model;
    int year;
    double miles, gallons, mpg;
};

#endif
