//
//  main.cpp
//  ch2-ex3
//
//  Created by Nico Savage on 4/18/23.
//

#include <iostream>
using namespace std;

int main() {
    string color;
    
    cout << "What is your favorite color?" << endl;
    cin >> color;
    
    int num1, num2, num3, average;
    num1 = 125;
    num2 = 28;
    num3 = -25;
    average = (num1 + num2 + num3) / 3;
    cout << "Number 1: " << num1 << " Number 2: " << num2 << " Number 3: " << num3 << endl << "Average: " << average << endl;
    
}
