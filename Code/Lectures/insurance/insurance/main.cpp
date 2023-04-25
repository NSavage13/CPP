//
//  main.cpp
//  insurance
//
//  Created by Nico Savage on 4/24/23.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double perHundred, totalMonthly;
    string name;
    char smoke, overweight;
    int age;
    
    cout << "What is your name >> ";
    getline(cin, name);
    //   input, variable, delimiter
    
    cout << "Welcome " << name << endl;
    cout << "How old are you " << name << endl;
    cin >> age;
    
    cout << "Do you smoke? (Y/N) " << name << "?\n";
    cin >> smoke;
    
    cout << "Are you overweight? (Y/N) " << name << endl;
    cin >> overweight;
    
    smoke = toupper(smoke);
    overweight = toupper(overweight);
    /*
     10 - 20 = 6.54
     21 - 30 = 7.77
     31 - 40 = 9.65
     41 - 50 = 10.21
     51 - 60 = 12.25
     61 - 100 = 14.45
     */
    
    if (age >= 10 && age <= 20){
        perHundred = 6.54;
    }else if (age > 20 && age <=30){
        perHundred = 7.77;
    }else if (age > 30 && age <=40){
        perHundred = 9.65;
    }else if (age > 40 && age <=50){
        perHundred = 10.21;
    }else if (age >50 && age <= 60){
        perHundred = 12.25;
    }else if (age>60 && age <= 100){
        perHundred = 14.45;
    }else {
        perHundred = -1;
        // do errors in else
        // test for all valid cases
    }
    if (smoke == 'Y'){
        perHundred += 0.02 * (100-age);
    }
    if (overweight == 'N'){
        perHundred *= (1 - .1);
    }
    cout << "You will pay $" << perHundred << " per hundred thousand, per month\n";
    
    
        
    
    
    
    return 0;
}
