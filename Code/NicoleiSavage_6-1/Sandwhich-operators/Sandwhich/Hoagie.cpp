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
void Hoagie::setLengthInFeet(string lengthInFeet){this->lengthInFeet = stoi(lengthInFeet);}
void Hoagie::setBaked(bool baked){this->baked = baked;}
int Hoagie::getLengthInFeet(){return lengthInFeet;}
bool Hoagie::getBaked(){return baked;}

double Hoagie::calculatePrice(){
    double cost = Sandwhich::calculatePrice();
    cost *= lengthInFeet;
    if (baked) {cost += 0.75 * lengthInFeet;return cost;}
    else{return cost;}}

string Hoagie::to_string(){
    stringstream ss;
    ss << "Bread Type: " << getBreadType() << "\n";
    ss << "Meat Type: " << getMeatType() << "\n";
    ss << "Cheese Type: " << getCheeseType() << "\n";
    ss << "Vegetables: " << getVegetables() << "\n";
    ss << "Condiments: " << getCondiments() << "\n";
    ss << "Length in Feet: " << getLengthInFeet() << "\n";
    ss << "Baked: " << boolalpha << getBaked() << "\n";
    ss << fixed << setprecision(2);
    ss << "Price: " << calculatePrice() << "\n";
    return ss.str();
}
ostream& operator<<(ostream& os,Hoagie& hg){os << hg.to_string();return os;}
istream& operator>>(istream& is, Hoagie& hg){
    cout << "Enter Bread Type: ";
    getline(is,hg.breadType);
    cout << "Enter Meat Type: ";
    getline(is,hg.meatType);
    cout << "Enter Cheese Type: ";
    getline(is,hg.cheeseType);
    cout << "Enter Vegetables: ";
    getline(is,hg.vegetables);
    cout << "Enter Condiments: ";
    getline(is,hg.condiments);
    cout << "Enter Length in Feet: ";
    is >> hg.lengthInFeet;
    cout << "Enter Baked: (1) for YES, (0) for NO: ";
    is >> hg.baked;
    cout << endl;
    return is;
}
bool Hoagie::operator==(Hoagie& hg){
    if (baked == hg.baked){return true;}else{return false;}
}
bool Hoagie::operator!=(Hoagie& hg){
    if (lengthInFeet != hg.lengthInFeet){return true;}else{return false;}
}
void Hoagie::hoagieCompare(Hoagie& h1, Hoagie& h2){
    cout << "~~Hoagie 1~~\n"<< h1 << "\n~~Hoagie 2~~\n" << h2 << endl;
    cout << "Between Hoagie 1 and Hoagie 2\n";
    if(h1==h2){cout << "Both hoagies are baked\n";}else{cout<<"One or both hoagies are not baked\n";}
    if(h1!=h2){cout<<"The hoagies are not the same legnth\n";}else{cout<<"The hoagies are the same legnth\n";}
}



