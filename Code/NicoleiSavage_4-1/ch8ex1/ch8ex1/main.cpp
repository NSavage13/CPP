//
//  main.cpp
//  ch8ex1
//
//  Created by Nico Savage on 5/1/23.
//
/*
    Write a C++ program that declares an array alpha of 50 components of type double. Initialize the array so that the first 25 components are equal to the square of the index variable, and the last 25 components are equal to three times the index variable. Output the array so that 10 elements per line are printed.

 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    double alpha[50];
    for (int i=0; i<25; i++){
        alpha[i] = i * i;
    }
    for (int i=25;i<=50;i++){
        alpha[i] = i * 3;
    }
    for (int i=0;i<50;i++){
        cout << alpha[i] << " ";
        if ((i+1) % 10 == 0){
            cout << endl;
        }
    }
    
    
    
}
