//
//  main.cpp
//  Sandwhich
//
//  Created by Nico Savage on 5/10/23.
//
#include "Sandwhich.hpp"
#include "Hoagie.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cctype>
 

using namespace std;

void getInfoSW(Sandwhich array[]);
void getInfoHG(Hoagie array[]);

int main(int argc, const char * argv[]) {
    
    Sandwhich s1 = Sandwhich();
    Sandwhich s2 = Sandwhich("White", "Steak", "Swiss", "Onions", "Mayo");
    Hoagie h1 = Hoagie();
    Hoagie h2 = Hoagie("Rye", "Steak", "Cheddar", "Lettuce and Tomatoe", "Mustard", 2, true);
    Sandwhich sw[2] = {s1, s2};
    Hoagie hg[2] = {h1, h2};
    getInfoSW(sw);
    getInfoHG(hg);
    cout << "Total Price: $" << fixed << setprecision(2) << s1.calculatePrice() + s2.calculatePrice() + h1.calculatePrice() + h2.calculatePrice() << endl;
    return 0;

    
    
    
}

void getInfoSW(Sandwhich array[]) {
    for (int i = 0; i < 2; i++) {
        cout << "Sandwich " << i+1 << endl;
        cout << array[i].to_string() << endl;
    }
}
void getInfoHG(Hoagie array[]) {
    for (int i = 0; i < 2; i++) {
        cout << "Hoagie " << i+1 << endl;
        cout << array[i].to_string() << endl;
    }
}


