//
//  main.cpp
//  FunctionTemplate
//
//  Created by Nico Savage on 5/24/23.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;


template<typename T>
T multiples(T x, int n) {
    T sum = static_cast<T>(1);  
    for (int i = 1; i <= n; ++i) {
        sum += i * x;
    }
    return sum;
}

int main() {
    
    cout << "multiples(3, 4) = " << multiples(3, 4) << endl;
    cout << "multiples(0.5, 4) = " << multiples(0.5, 4) << endl;

    return 0;
}

