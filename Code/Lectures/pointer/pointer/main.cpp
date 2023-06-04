//
//  main.cpp
//  pointer
//
//  Created by Nico Savage on 5/31/23.
//
#include "FoodItem.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    double payroll = 12345.67;
    double tax = payroll * .07;
    
    //pointers hold the adress of a variable
    double *payPtr, *taxPtr;
        // * is called the dereference operator
    // assign memory location to pointer using & - adress of
    
    payPtr = &payroll;
    
    cout << "Payroll is at " << *payPtr << endl;
    double val = *payPtr;
    
    cout << "Payroll is " << fixed << setprecision(2)<< val << endl;
    
    

}
