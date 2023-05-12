//
//  car.cpp
//  5-1
//
//  Created by Nico Savage on 5/9/23.
//

#include "Car.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
Car::Car(){
    make = "";
    model = "";
    year = 0;
    miles = 0;
    gallons = 0;
    mpg = 0;
};
Car::Car(string make,string model,int year,double miles,double gallons,double mpg){
    this->make = make;
    this->model = model;
    this->year = year;
    this->miles = miles;
    this->gallons = gallons;
};

string Car::getMake() const{
    return make;
}
string Car::getModel() const{
    return model;
}
int Car::getYear() const{
    return year;
}
double Car::getMiles() const{
    return miles;
}
double Car::getGallons() const{
    return gallons;
}
double Car::getMpg() const{
    return mpg;
}

double Car::getDistance() const{
    return mpg * gallons;
}
double Car::getCost() const{
    return 3.09 / (mpg*gallons);
}

void Car::setMake(string make) {
    this->make = make;
}

void Car::setModel(string model) {
    this->model = model;
}

void Car::setYear(int year) {
    this->year = year;
}

void Car::setMiles(double miles) {
    this->miles = miles;
}

void Car::setGallons(double gallons) {
    this->gallons = gallons;
}

void Car::setMpg(double mpg) {
    this->mpg = mpg;
}

string Car::to_string() const {
    return make + " " + model + " " + std::__1::to_string(year) + "\n";
}

