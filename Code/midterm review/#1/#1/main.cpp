//
//  main.cpp
//  #1
//
//  Created by Nico Savage on 5/15/23.
/*
 Create an array storing 30 random numbers (between 1 and 50) of type int.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;



int main(int argc, const char * argv[]) {
    int arr[30];
    
    for (int i = 0; i < 30; i++) {
        arr[i] = rand() % 50 + 1;
        cout << arr[i] << endl;
    }
    
}
