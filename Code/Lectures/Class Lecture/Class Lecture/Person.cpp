//
//  Person.cpp
//  Class Lecture
//
//  Created by Nico Savage on 5/15/23.
//

#include "Person.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

Person::Person(){
    firstName = "Nico";
    lastName = "Savage";
    userName = "nsavage";
}
Person::~Person(){
    // destructor
    //called when variable goes out of scope
}
Person::Person(string fn, string ln, string un){
    this->firstName = fn;
    this->lastName = ln;
    this->userName = un;
}
string Person::getFirstName(){
    return firstName;
}
string Person::getLastName(){
    return lastName;
}
string Person::getUserName(){
    return userName;
}
void Person::setFirstName(string fn){
    firstName = fn;
}
void Person::setLastName(string ln){
    lastName = ln;
}
void Person::setUserName(string un){
    userName = un;
}
string Person::toString(){
    return "First name: " + firstName + "\nLast name: " + lastName + "\nUsername: " + userName;
}



