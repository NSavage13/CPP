//
//  Person.hpp
//  Class Lecture
//
//  Created by Nico Savage on 5/15/23.
//

#ifndef Person_hpp
#define Person_hpp
#pragma once // only do it once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
#include <stdio.h>

class Person{
public:
    Person();
    ~Person();
    Person(string fn,string ln, string un);
    
    string getFirstName();
    string getLastName();
    string getUserName();
    void setFirstName(string);
    void setLastName(string);
    void setUserName(string);
    string toString();
    
protected:
    string firstName, lastName, userName;
        
};

#endif /* Person_hpp */
