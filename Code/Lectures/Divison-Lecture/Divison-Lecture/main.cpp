//
//  main.cpp
//  Divison-Lecture
//
//  Created by Nico Savage on 4/20/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int num = 45;
    int lastDigit = num % 10;
    // cout << lastDigit << endl;
    if (lastDigit == 5 || lastDigit == 0){
        cout << num << " is divisible by 5" << endl;
    }else {
        cout << num << " is NOT divisible by 5" << endl;
    }
    
    return 0;
}
