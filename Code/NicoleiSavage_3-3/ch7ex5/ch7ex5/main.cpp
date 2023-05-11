//
//  main.cpp
//  ch7ex5
//
//  Created by Nico Savage on 4/26/23.
//
/*
 Write a program that can be used to calculate the federal tax. The tax is calculated as follows: For single people, the standard exemption is $4,000; for married people, the standard exemption is $7,000. A person can also put up to 6% of his or her gross income in a pension plan. The tax rates are as follows: If the taxable income is:
 Between $0 and $15,000, the tax rate is 15%.
 Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable income over $15,000.
 Over $40,000, the tax is $8,460 plus 35% of the taxable income over $40,000.
 Prompt the user to enter the following information:
 
 Marital status
 
 If the marital status is “married,” ask for the number of children under the age of 14
 
 Gross salary (If the marital status is “married” and both spouses have income, enter the combined salary.)
 
 Percentage of gross income contributed to a pension fund

 Your program must consist of at least the following functions:

    A) Function getData: This function asks the user to enter the relevant data.

    B) Function taxAmount: This function computes and returns the tax owed.

 To calculate the taxable income, subtract the sum of the standard exemption, the amount contributed to a pension plan, and the personal exemption, which is $1,500 per person. (Note that if a married couple has two children under the age of 14, then the personal exemption is $1,500 * 4 = $6,000
 
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
enum ms {MARRIED, SINGLE};
ms status;
int maritalStatus, numChildren;
double pensionRate, personalEx, stdEx, taxableIncome, grossSalary, taxRate, tax;


int getData(){
    cout << "If you are married enter (1)\nIf you are single enter (0)\n";
    cin >> maritalStatus;
    
        if (maritalStatus == 1){
            status = MARRIED;
            cout << "How many kids below the age of 14 do you have?\n";
            cin >> numChildren;
        }else if (maritalStatus == 0){
            status = SINGLE;
        }else {
            cout << "Error. Wrong input.\n";
            return 1;
        }
    cout << "What is your household gross income?\n";
    cin >> grossSalary;
    cout << "Percentage Contributed to Pension Fund (0-6%): ";
        cin >> pensionRate;
        if (pensionRate < 0 || pensionRate > 6) {
            cout << "Invalid percentage. Please enter a number between 0 and 6." << endl;
            return 1;
        }
    return 0;
}

// Between $0 and $15,000, the tax rate is 15%.
//Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable income over $15,000.
//Over $40,000, the tax is $8,460 plus 35% of the taxable income over $40,000.

double taxAmount(){
    if(status == SINGLE){
        stdEx = 4000;
        personalEx = 1500;
    }else if (status == MARRIED){
        stdEx = 7000;
        personalEx = 1500 * (2 + numChildren);
    }
    double pensionAmount = grossSalary * pensionRate / 100;
    taxableIncome = grossSalary - stdEx - personalEx - pensionAmount;
    cout << taxableIncome << "\n";
    if (taxableIncome <= 15000){
        taxRate = 0.15;
        tax = taxableIncome * taxRate;
    }else if (taxableIncome >= 15001 && taxableIncome <= 40000){
        taxRate = 0.25;
        tax = ((taxableIncome - 15000) * taxRate) + 2250;
    }else if (taxableIncome > 40000){
        taxRate = 0.35;
        tax = ((taxableIncome - 40000) * taxRate) + 8460;
    }
    return tax;
}



int main() {
    getData();
    taxAmount();
    
    printf("Your federal tax will be $%.2f\n", tax);
    
    
    
    
    return 0;
}


