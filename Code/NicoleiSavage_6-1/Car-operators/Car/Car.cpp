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
    year = 10;
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
    this->mpg = mpg;

};

string Car::getMake()  {
    return make;
}
string Car::getModel()  {
    return model;
}
int Car::getYear()  {
    return year;
}
double Car::getMiles()  {
    return miles;
}
double Car::getGallons()  {
    return gallons;
}
double Car::getMpg()  {
    return mpg;
}

double Car::getDistance()  {
    return mpg * gallons;
}
double Car::getCost()  {
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

string Car::to_string()   {
    stringstream ss;
    ss << "Make: " << this->make;
    ss  << "\nModel: " << this->model;
    ss  << "\nYear: " << this->year;
    ss  << "\nMiles: " << this->miles;
    ss  << "\nGallons: " << this->gallons;
    ss  << "\nMPG: " << this->mpg << endl;
    
    return ss.str();
}
ostream& operator<<(ostream& os, Car& car) {
    os << car.to_string();
    return os;
}
istream& operator>>(istream& is, Car& car){
    cout << "Enter make: ";
    getline(is,car.make);
    cout << "Enter model: ";
    getline(is,car.model);
    cout << "Enter year: ";
    is >> car.year;
    cout << "Enter miles: ";
    is >> car.miles;
    cout << "Enter gallons: ";
    is >> car.gallons;
    cout << "Enter mpg: ";
    is >> car.mpg;
    return is;

}
bool Car::operator<(Car& c){
    return this->getYear() < c.getYear();
}
bool Car::operator>(Car& c){
    return this->getYear() > c.getYear();
}
bool Car::operator==(Car& c){
    return this->getYear() == c.getYear();
}
bool Car::operator!=(Car& c){
    return this->getYear() != c.getYear();
}
bool Car::operator<=(Car& c){
    return this->getYear() <= c.getYear();
}
bool Car::operator>=(Car& c){
    return this->getYear() >= c.getYear();
}
Car Car::operator+(Car& c){
    Car result;
    result.year = this->getYear() + c.getYear();
    return result;
}
Car Car::operator-(Car& c){
    Car result;
    result.year = this->getYear() - c.getYear();
    return result;
}
Car Car::operator*(Car& c){
    Car result;
    result.year = this->getYear() * c.getYear();
    return result;
}
Car Car::operator/(Car& c){
    Car result;
    result.year = this->getYear() / c.getYear();
    return result;
}
Car Car::operator++(){
    this->year++;
    return *this;
}
Car Car::operator++(int){
    Car temp = *this;
    this->year++;
    return temp;
}
void Car::carOperations(Car& car1,Car& car2){
    cout << "~~Binary Operators~~" << endl;
    cout << "Car 1 year: "<< car1.getYear() << endl;
    car1 = car1-car2;
    cout << "Car1 - Car2 = "<< car1.getYear() << endl;
    car1 = car1+car2;
    cout << "Car1 + Car2 = "<< car1.getYear() << endl;
    car1 = car1*car2;
    cout << "Car1 * Car2 = "<< car1.getYear() << endl;
    car1 = car1/car2;
    cout << "Car1 / Car2 = "<< car1.getYear() << endl;
    car1++;
    cout << "Car1++ = "<< car1.getYear() << endl;
    ++car1;
    cout << "++Car1 = "<< car1.getYear() << endl;
    cout << "Car 1 year: "<< car1.getYear() << endl;
    cout <<endl;
}
void Car::carComparisons(Car& car1,Car& car2) {
    cout << "~~Car 1~~\n" << car1 << "\n~~Car 2~~\n" << car2 << endl;
    cout << "~~Comparison~~" << endl;
    if (car1 < car2) {
        cout << "Car 1 is older than Car 2" << endl;
    }
    if (car1 > car2) {
        cout << "Car 1 is newer than Car 2" << endl;
    }
    if (car1 <= car2) {
        cout << "Car 1 is either older or the same as Car 2" << endl;
    }
    if (car1 >= car2) {
        cout << "Car 1 is either newer or the same as Car 2" << endl;
    }
    if (car1 == car2) {
        cout << "Car 1 is equal to Car 2" << endl;
    }
    if (car1 != car2) {
        cout << "Car 1 is not equal to Car 2" << endl;
    }
    cout << endl;
}




