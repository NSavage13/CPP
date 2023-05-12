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

string Sandwhich::getBreadType(){
    return breadType;
}
string Sandwhich::getMeatType(){
    return meatType;
}
string Sandwhich::getCheeseType(){
    return cheeseType;
}
string Sandwhich::getVegetables(){
    return vegetables;
}
string Sandwhich::getCondiments(){
    return condiments;
}
double Sandwhich::getPrice(){
    return price;
}

double Sandwhich::calculatePrice(){
    double cost = 0;
    
    if (breadType == "White"){
        cost += 1.50;
    }else if (breadType == "Wheat"){
        cost += 2.00;
    }else if (breadType == "Rye"){
        cost += 2.50;
    }
    
    if(meatType == "Ham"){
        cost += 2.75;
    }else if (meatType == "Turkey"){
        cost += 3.25;
    }else if (meatType == "Steak"){
        cost += 4.00;
    }
    
    if(cheeseType == "Cheddar"){
        cost += 1.00;
    }else if (cheeseType == "Swiss"){
        cost += 1.25;
    }else if (cheeseType == "Provolone"){
        cost += 1.50;
    }
    return cost;
}


    string Sandwhich::to_string(){
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Bread : " << breadType;
    ss << "\nMeat: " << meatType;
    ss << "\nCheese: " << cheeseType;
    ss << "\nVegetables: " << vegetables;
    ss << "\nCondiments: " << condiments;
    ss << "\nPrice: $" << calculatePrice() << endl;
    
    return ss.str();
}
