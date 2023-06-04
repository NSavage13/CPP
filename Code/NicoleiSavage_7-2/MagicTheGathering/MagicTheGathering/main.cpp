//
//  main.cpp
//  MagicTheGathering
//
//  Created by Nico Savage on 5/30/23.
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Card.hpp"

using namespace std;

void shuffleDeck(vector<Card>& deck);
void printDeck(vector<Card>& deck);
void fight(vector<Card>& deck1, vector<Card>& deck2);

int main() {
    // 0 sets it to null and becomes the current
    srand(static_cast<unsigned int>(time(0)));
    
    vector<Card> deck1;
    vector<Card> deck2;
    
    // emplace_back allows you to not call the constructor
    deck1.emplace_back("Iron Dragon", 10, 20);
    deck1.emplace_back("Fire Mage", 8, 15);
    deck1.emplace_back("Stone Golem", 12, 25);
    deck1.emplace_back("Thunderbolt", 6, 10);
    deck1.emplace_back("Ice Witch", 9, 18);

    deck2.push_back(Card("Dark Knight", 11, 22));
    deck2.push_back(Card("Nature Druid", 7, 13));
    deck2.push_back(Card("Water Elemental", 13, 28));
    deck2.push_back(Card("Lightning Strike", 5, 12));
    deck2.push_back(Card("Frost Giant", 10, 20));

    cout << "Player 1's deck:" << endl;
    printDeck(deck1);
    cout << "Player 2's deck:" << endl;
    printDeck(deck2);

    fight(deck1, deck2);

    return 0;
}

void shuffleDeck(vector<Card>& deck) {
    for (int i = 0; i < deck.size()-1;i++) {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }

}
void printDeck( vector<Card>& deck) {
    for ( Card& card : deck) {
        cout << card.getName() << " (ATT=" << card.getDamage() << " HP=" << card.getHealth() << ")" << endl;
    }
    cout << "-----------------------" << endl;
}
void fight(vector<Card>& deck1, vector<Card>& deck2) {
    int round = 1;
    while (!deck1.empty() && !deck2.empty()) {
        shuffleDeck(deck1);
        shuffleDeck(deck2);
        
        cout << "Round " << round << endl;
        Card& card1 = deck1.back();
        Card& card2 = deck2.back();
        cout << "Player 1 plays: " << card1.getName() << endl;
        cout << "Player 2 plays: " << card2.getName() << endl;

        int damage1 = rand() % card1.getDamage() + 1;
        int damage2 = rand() % card2.getDamage() + 1;

        cout << "Player 1 deals " << damage1 << " damage to Player 2's card." << endl;
        cout << "Player 2 deals " << damage2 << " damage to Player 1's card.\n" << endl;

        card2.takeDamage(damage1);
        card1.takeDamage(damage2);

        if (card1.isDead()) {
            cout << "Player 1's card " << card1.getName() << " died." << endl;
            deck1.pop_back();
        }
        if (card2.isDead()) {
            cout << "Player 2's card " << card2.getName() << " died." << endl;
            deck2.pop_back();
        }

        cout << "Player 1's deck:" << endl;
        printDeck(deck1);
        cout << "Player 2's deck:" << endl;
        printDeck(deck2);

        ++round;
    }

    if (deck1.empty()) {
        cout << "Player 2 wins!" << endl;
    } else {
        cout << "Player 1 wins!" << endl;
    }
}
