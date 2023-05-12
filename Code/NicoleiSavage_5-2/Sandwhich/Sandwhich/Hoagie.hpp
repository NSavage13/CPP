//
//  Hoagie.hpp
//  Sandwhich
//
//  Created by Nico Savage on 5/11/23.
/*
 Create a class called Hoagie that inherits from Sandwich. Add two class variables called length in feet and baked. Override the cost calculation method as follows.
 Total price = price*feet. If the hoagie is baked, add $.75 per foot to the price.
 */

#ifndef Hoagie_hpp
#define Hoagie_hpp
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <string>
#include "Sandwhich.hpp"

using namespace std;

class Hoagie : public Sandwhich {
private:
    int lengthInFeet;
    bool baked;
    
public:
    Hoagie();
    Hoagie(string breadtype,string meatType,string cheeseType,string vegetables,string condiments, int lengthInFeet, bool baked);
    void setLengthInFeet(string lengthInFeet);
    void setBaked(bool baked);
    int getLengthInFeet();
    bool getBaked();
    double calculatePrice();
    
    string to_string();

};


#endif /* Hoagie_hpp */
