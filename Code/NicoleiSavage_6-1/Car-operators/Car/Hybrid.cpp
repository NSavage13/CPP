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
    ss << "Battery Capacity: " << this->batteryCapacity << "%";
    ss << "\nBattery Charge: " << this->batteryChargePercent << "%";
    ss << fixed << setprecision(0);
    ss << "\nRange: " << this->calculateRange() << " miles\n";
    return ss.str();
}

ostream& operator<<(ostream& os, Hybrid& h){
    os << h.to_string();
    return os;
}
istream& operator>>(istream& is, Hybrid& h){
    cout << "Hybrid Car Input\n";
    cout << "Enter make: ";
    getline(is, h.make);
    cout << "Enter model: ";
    getline(is, h.model);
    cout << "Enter year: ";
    is >> h.year;
    cout << "Enter miles: ";
    is >> h.miles;
    cout << "Enter gallons: ";
    is >> h.gallons;
    cout << "Enter mpg: ";
    is >> h.mpg;
    cout << "Enter battery capacity: ";
    is >> h.batteryCapacity;
    cout << "Enter battery charge percent: ";
    is >> h.batteryChargePercent;
    cout << endl;
    
    return is;
}
bool Hybrid::operator==(Hybrid& h){
    return this->getBatteryChargePercent() == h.getBatteryChargePercent();

}
bool Hybrid::operator!=(Hybrid& h){
    return this->getBatteryChargePercent() != h.getBatteryChargePercent();
}
void Hybrid::hybridComparisons(Hybrid& h1, Hybrid& h2){
    cout << "~~Hybrid 1~~\n" << h1 << "\n~~Hybrid 2~~\n" << h2 << endl;
    if(h1 == h2){
        cout << "Hybrid 1 has the same charge percent as Hybrid 2" << endl;
    }
    if(h1 != h2){
        cout << "Hybrid 1 does not have the same charge percent as Hybrid 2" << endl;
    }
    
}






