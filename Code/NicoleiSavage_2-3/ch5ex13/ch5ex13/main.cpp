//
//  main.cpp
//  ch5ex13
//
//  Created by Nico Savage on 4/24/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int x = 75;
    int counter = 0;
    
    do {
        cout << x << endl;
        if(x % 2 == 0){
            x = x/2;
        }else {
            x = 3*x + 1;
        }
        counter ++;
        
    }while (x!= 1);
    
    cout << x << endl;
    cout << "k = " << counter << endl;
    
    return 0;
}
