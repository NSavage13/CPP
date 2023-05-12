//
//  Sandwhich.hpp
//  Sandwhich
//
//  Created by Nico Savage on 5/10/23.
/*
 Create a class called Sandwich. The class will calculate the cost of a sandwich, based on the items you choose. Your class will hold the bread type, meat type, cheese type, vegetables, condiment, and price. Create a method that calculates the price of the sandwich based on the bread type, meat type, and cheese type.
 For clarity, different breads cost a different amount, likewise meats and cheeses each can cost a different amount. Create as many additional constructors as makes sense. Create whatever methods you think are appropriate.
 */

#ifndef Sandwhich_hpp
#define Sandwhich_hpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
#include <stdio.h>

class Sandwhich {
private:
    string breadType, meatType, cheeseType, vegetables, condiments;
    double price;
    
    
public:
    Sandwhich();
    Sandwhich(string breadtype,string meatType,string cheeseType,string vegetables,string condiments);
    string getBreadType();
    string getMeatType();
    string getCheeseType();
    string getVegetables();
    string getCondiments();
    double getPrice();
    double calculatePrice();
    
    
    
    
    void setBreadtype(string breadType);
    void setMeatType(string meatType);
    void setCheeseType(string cheeseType);
    void setVegetables(string vegetables);
    void setCondiments(string condiments);
    void setPrice(double price);
    
    
    string to_string();
};


#endif /* Sandwhich_hpp */
