//
//  Card.cpp
//  MagicTheGathering
//
//  Created by Nico Savage on 5/30/23.
//

#include "Card.hpp"


Card::Card(string name, int damage, int health)
        : name(name), damage(damage), health(health) {}

string Card::getName()  {
    return name;
}
int Card::getDamage()  {
    return damage;
}
int Card::getHealth()  {
    return health;
}
void Card::takeDamage(int points) {
    health -= points;
}
bool Card::isDead()  {
    return health <= 0;
}





