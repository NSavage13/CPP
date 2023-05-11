//
//  main.cpp
//  Payroll
//
//  Created by Nico Savage on 5/1/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// function prototype here
void printMyName();
double grossPay(double rate, int hours);
void inputData(double &rate, int &hours);
void output(double, int, double);


int main() {
    double rate = 15.5;
    int hours = 40;
    double gross = 0;
    string again = "Y";
    do{
        printMyName();
        inputData(rate, hours);
        gross = grossPay(rate, hours);
        output(rate, hours, gross);
        cout << "More payroll to calculate (Y/N)";
        cin >> again;
        
    }while(toupper(again.at(0))== 'Y');
    return 0;
}


// function definition here

void output(double rate, int hours, double gross){
    
    printf("Rate = $%.2f\nHours = %d\nGross pay is $%.2f\n",rate,hours, gross);
}
void inputData(double &rate, int &hours){
    cout << "Enter the rate $\n";
    cin >> rate;
    
    cout << "Enter the amount of hours worked\n";
    cin >> hours;
}

double grossPay(double rate, int hours){
    double gross = 123;
    if(hours >= 0 && hours <= 40){
        gross = rate * hours;
    }else if (hours > 40){
        gross = 40 * rate + (hours - 40) * rate * 1.5;
    }else {
        gross = -1;
    }
    return gross;
}

void printMyName(){
    cout << "Nicolei Savage\n";
    
}
