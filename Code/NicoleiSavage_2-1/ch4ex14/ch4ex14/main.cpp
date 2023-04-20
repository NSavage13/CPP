//
//  main.cpp
//  ch4ex14
//
//  Created by Nico Savage on 4/20/23.
//


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    double h;
    int fee = 0;
    
    cout << "How many hours did you park?\n";
    cin >> h;
    
    if (h>=0 && h<=3){
        fee = 5;
    }else if (h>3 && h<=9){
        fee = 6 * int(h+1);
    }else if (h>9 && h<=24){
        fee = 60;
    }else {
        cout << "Inavlid input" << endl;
    }
    
    cout << "Your fee is: $" << fee << endl;
    
    return 0;
}
