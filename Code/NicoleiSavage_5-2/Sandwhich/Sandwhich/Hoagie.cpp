//
//  Hoagie.cpp
//  Sandwhich
//
//  Created by Nico Savage on 5/11/23.
//

#include "Hoagie.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

Hoagie::Hoagie() : Sandwhich(){
    lengthInFeet = 4;
    baked = true;
}
Hoagie::Hoagie(string breadtype,string meatType,string cheeseType,string vegetables,string condiments, int lengthInFeet, bool baked) : Sandwhich(breadtype, meatType, cheeseType, vegetables, condiments){
    this->lengthInFeet = lengthInFeet;
    this->baked = baked;
}
void Hoagie::setLengthInFeet(string lengthInFeet){
    this->lengthInFeet = stoi(lengthInFeet);
}
void Hoagie::setBaked(bool baked){
    this->baked = baked;
}
int Hoagie::getLengthInFeet(){
    return lengthInFeet;
}
bool Hoagie::getBaked(){
    return baked;
}
double Hoagie::calculatePrice(){
    double cost = Sandwhich::calculatePrice();
    cost *= lengthInFeet;
    if (baked) {
        cost += 0.75 * lengthInFeet;
        
        return cost;
    }else{
        return cost;
    }
}

string Hoagie::to_string(){
    stringstream ss;
    ss << "Bread Type: " << getBreadType() << "\n";
    ss << "Meat Type: " << getMeatType() << "\n";
    ss << "Cheese Type: " << getCheeseType() << "\n";
    ss << "Vegetables: " << getVegetables() << "\n";
    ss << "Condiments: " << getCondiments() << "\n";
    ss << "Length in Feet: " << getLengthInFeet() << "\n";
    ss << "Baked: " << getBaked() << "\n";
    ss << fixed << setprecision(2);
    ss << "Price: " << calculatePrice() << "\n";
    return ss.str();
}


