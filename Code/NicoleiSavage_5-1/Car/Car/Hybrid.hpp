//
//  Hybrid.hpp
//  5-1
//
//  Created by Nico Savage on 5/10/23.
//

#ifndef Hybrid_hpp
#define Hybrid_hpp
#include "Car.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
#include <stdio.h>

class Hybrid : public Car {
private:
    double batteryCapacity, batteryChargePercent;
    
public:
    Hybrid();
    Hybrid(string make,string model,int year,double miles,double gallons,double mpg, double batteryCapacity, double batteryChargePercent);
    void setBatteryCapacity(double batteryCapacity);
    void setBatteryChargePercent(double batteryChargePercent);
    double getBatteryCapacity();
    double getBatteryChargePercent();
    double calculateRange();
    void chargeBattery(double amount);
    string to_string();
    
};
#endif /* Hybrid_hpp */
