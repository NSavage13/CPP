//
//  Card.hpp
//  MagicTheGathering
//
//  Created by Nico Savage on 5/30/23.
//

#ifndef Card_hpp
#define Card_hpp
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
#include <stdio.h>

class Card {
public:
    Card(string name, int damage, int health);
    Card();
    string getName();
    int getDamage();
    int getHealth();
    void takeDamage(int points);
    bool isDead();
      
private:
    string name;
    int damage;
    int health;
};


#endif /* Card_hpp */
