//
//  Hybrid.cpp
//  5-1
//
//  Created by Nico Savage on 5/10/23.
//

#include "Hybrid.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

Hybrid::Hybrid() : Car() {
    batteryCapacity = 0.0;
    batteryChargePercent = 0.0;
}

Hybrid::Hybrid(string make,string model, int year, double miles, double gallons, double mpg, double batteryCapacity, double batteryChargePercent)
: Car(make, model, year, miles, gallons, mpg){
    this->batteryCapacity = batteryCapacity;
    this->batteryChargePercent = batteryChargePercent;
}
void Hybrid::setBatteryCapacity(double batteryCapacity) {
    this->batteryCapacity = batteryCapacity;
}

void Hybrid::setBatteryChargePercent(double batteryChargePercent) {
    this->batteryChargePercent = batteryChargePercent;
}
double Hybrid::getBatteryCapacity(){
    return batteryCapacity;
}
double Hybrid::getBatteryChargePercent(){
    return batteryChargePercent;
}
double Hybrid::calculateRange(){
    return this->batteryChargePercent * 10;
}
void Hybrid::chargeBattery(double amount){
    this->batteryChargePercent += amount;
    if(batteryChargePercent > 100){
        batteryChargePercent = 100;
    }
}
string Hybrid::to_string() {
    stringstream ss;
    ss << fixed << setprecision(1);
    ss << Car::to_string();
    ss << "Battery Capacity: " << this->batteryCapacity;
    ss << "\nBattery Charge: " << this->batteryChargePercent << "%";
    ss << std::fixed << std::setprecision(0);
    ss << "\nRange: " << this->calculateRange() << " miles\n";
    return ss.str();
}



