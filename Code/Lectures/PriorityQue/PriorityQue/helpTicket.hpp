//
//  helpTicket.hpp
//  PriorityQue
//
//  Created by Nico Savage on 6/6/23.
//

#ifndef helpTicket_hpp
#define helpTicket_hpp
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

#pragma once
using namespace std;

#include <stdio.h>

class helpTicket{
private:
    int priority;
    string description;
public:
    helpTicket();
    ~helpTicket();
    helpTicket(string desc, int pri = 0){
        description = desc;
        priority = pri;
    }
    string getDescription(){
        return description;
    }
    friend bool operator<(const helpTicket &ticket1, const helpTicket &ticket2);
    friend bool operator>(const helpTicket &ticket1, const helpTicket &ticket2);
    friend bool operator>= (const helpTicket &ticket1, const helpTicket &ticket2);

    friend bool operator<= (const helpTicket &ticket1, const helpTicket &ticket2);
    
    friend bool operator== (const helpTicket &ticket1, const helpTicket &ticket2){
        return ticket1.priority == ticket2.priority;
    }
    
    friend bool operator!= (const helpTicket &ticket1, const helpTicket &ticket2){
        return ticket1.priority != ticket2.priority;
    }
    
};

#endif /* helpTicket_hpp */
