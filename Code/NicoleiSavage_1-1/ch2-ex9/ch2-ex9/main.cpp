//
//  main.cpp
//  ch2-ex9
//
//  Created by Nico Savage on 4/18/23.
//
//  USED TO SOLVE SKIPPED INPUT PROBLEM
//  cin.ignore(1000, "\n);
//  cin.clear;

#include <iostream>
using namespace std;
int main() {
    double test1, test2, test3, test4, test5;
    
    cout << "Enter your 5 test scores.\n";
    cin >> test1;
    cin >> test2;
    cin >> test3;
    cin >> test4;
    cin >> test5;
    
    double testAverage = (test1 + test2 + test3 + test4 + test5) / 5;
    cout << "Your average test score is " << testAverage << endl;
    
    return 0;
}
