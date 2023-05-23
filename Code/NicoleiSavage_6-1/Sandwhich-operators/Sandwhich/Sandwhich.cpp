//
//  Sandwhich.cpp
//  Sandwhich
//
//  Created by Nico Savage on 5/10/23.
//

#include "Sandwhich.hpp"

#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

Sandwhich::Sandwhich() : breadType("Wheat"), meatType("Ham"), cheeseType("Cheddar"),vegetables("Lettuce, Onion, Tomatoe"),condiments("Mustard"),price(calculatePrice()){}
Sandwhich::Sandwhich(string breadtype,string meatType,string cheeseType,string vegetables,string condiments){
    this->breadType = breadtype;
    this->meatType = meatType;
    this->cheeseType = cheeseType;
    this->vegetables = vegetables;
    this->condiments = condiments;
    this->price = calculatePrice();
    
}

string Sandwhich::getBreadType(){return breadType;}
string Sandwhich::getMeatType(){return meatType;}
string Sandwhich::getCheeseType(){return cheeseType;}
string Sandwhich::getVegetables(){return vegetables;}
string Sandwhich::getCondiments(){return condiments;}
double Sandwhich::getPrice(){return price;}

double Sandwhich::calculatePrice(){
    
    double cost = 0;
    if (breadType == "White"){cost += 1.50;}
    else if (breadType == "Wheat"){cost += 2.00;}
    else if (breadType == "Rye"){cost += 2.50;}
    
    if(meatType == "Ham"){cost += 2.75;}
    else if (meatType == "Turkey"){cost += 3.25;}
    else if (meatType == "Steak"){cost += 4.00;}
    
    if(cheeseType == "Cheddar"){cost += 1.00;}
    else if (cheeseType == "Swiss"){cost += 1.25;}
    else if (cheeseType == "Provolone"){cost += 1.50;}
    price = cost;
    return price;
}

string Sandwhich::to_string(){
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Bread: " << breadType;
    ss << "\nMeat: " << meatType;
    ss << "\nCheese: " << cheeseType;
    ss << "\nVegetables: " << vegetables;
    ss << "\nCondiments: " << condiments;
    ss << "\nPrice: $" << price << endl;
    return ss.str();
}

ostream& operator<<(ostream& os, Sandwhich& s){
    os << s.to_string();
    return os;
}
istream &operator>>(istream& is, Sandwhich& s){
    cout << "Enter the bread type: ";
    is >> s.breadType;
    cout << "Enter the meat type: ";
    is >> s.meatType;
    cout << "Enter the cheese type: ";
    is >> s.cheeseType;
    cout << "Enter the vegetables: ";
    is >> s.vegetables;
    cout << "Enter the condiments: ";
    is >> s.condiments;
    s.price = s.calculatePrice();
    return is;
}
bool Sandwhich::operator==(Sandwhich& s){return (breadType ==s.breadType);}
bool Sandwhich::operator!=(Sandwhich& s){return (meatType !=s.meatType);}
bool Sandwhich::operator<(Sandwhich& s){return (calculatePrice()< s.calculatePrice());}
bool Sandwhich::operator>(Sandwhich& s){return (calculatePrice()> s.calculatePrice());}
bool Sandwhich::operator<=(Sandwhich& s){return (calculatePrice() <= s.calculatePrice());}
bool Sandwhich::operator>=(Sandwhich& s){return (calculatePrice() >= s.calculatePrice());}

Sandwhich Sandwhich::operator*(Sandwhich& s){Sandwhich temp;temp.price = price * s.price;return temp;}
Sandwhich Sandwhich::operator/(Sandwhich& s){Sandwhich temp;temp.price = price / s.price;return temp;}
Sandwhich Sandwhich::operator+(Sandwhich& s){Sandwhich temp;temp.price = price + s.price;return temp;}
Sandwhich Sandwhich::operator-(Sandwhich& s){Sandwhich temp;temp.price = price - s.price;return temp;}
Sandwhich Sandwhich::operator++(){
    price++;
    return *this;}
Sandwhich Sandwhich::operator++(int)
{
    Sandwhich temp = *this;
    price++;
    return temp;
    
}

void Sandwhich::sandOperators(Sandwhich& s1, Sandwhich& s2){
    Sandwhich s1Copy = s1;
    cout << fixed << setprecision(2);
    cout << "Sandwhich 1 price: $" << s1Copy.getPrice() << endl;
    s1Copy=s1Copy+s2;
    cout << "Sandwhich 1 + Sandwhich 2 = $" << s1Copy.getPrice() << endl;
    s1Copy=s1Copy-s2;
    cout << "Sandwhich 1 - Sandwhich 2 = $" << s1Copy.getPrice() << endl;
    s1Copy=s1Copy*s2;
    cout << "Sandwhich 1 * Sandwhich 2 = $" << s1Copy.getPrice() << endl;
    s1Copy=s1Copy/s2;
    cout << "Sandwhich 1 / Sandwhich 2 = $" << s1Copy.getPrice() << endl;
    s1Copy++;
    cout << "Sandwhich 1++ = $" << s1Copy.getPrice() << endl;
    ++s1Copy;
    cout << "++Sandwhich 1 = $" << s1Copy.getPrice() << endl;
    cout << endl;
}
void Sandwhich::sandCompare(Sandwhich& s1, Sandwhich& s2){
    cout << "~~Sandwhich 1~~\n"<< s1 << "\n~~Sandwhich 2~~\n" << s2 << endl;
    cout << "Between Sandwhich 1 and Sandwhich 2\n";
    if (s1==s2){cout << ">>Bread type is the same\n";}else{cout << ">>Bread is not the same\n";}
    if(s1!=s2){cout << ">>Meat type is not the same\n";}else{cout << ">>Meat type is the same\n";}
    if(s1<s2){cout << ">>Sandwhich 1 is cheaper\n";}
    if(s1>s2){cout << ">>Sandwhich 2 is cheaper\n";}
    if(s1<=s2){cout << ">>Sandwhich 1 is cheaper or equal\n";}
    if(s1>=s2){cout << ">>Sandwhich 2 is cheaper or equal\n";}
    cout << endl;
}




