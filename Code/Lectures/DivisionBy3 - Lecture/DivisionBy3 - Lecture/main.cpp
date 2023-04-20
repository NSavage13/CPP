//
//  main.cpp
//  DivisionBy3 - Lecture
//
//  Created by Nico Savage on 4/20/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string number = "1457";
    int len = number.length();
    int total = 0;
    for(int c=0; c< len; c++){
        cout << number.at(c) << endl;
        total += (number.at(c) - '0');
    }
   // cout << total << endl;
    if (total % 3 == 0){
        cout << number << " is divisble by 3" << endl;
    }else {
        cout << number << " is NOT divisble by 3" << endl;
    }
    return 0;
}
