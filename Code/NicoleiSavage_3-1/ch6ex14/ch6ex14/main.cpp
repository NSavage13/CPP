//
//  main.cpp
//  ch6ex14
//
//  Created by Nico Savage on 4/24/23.
/*
 During the tax season, every Friday, the J&J accounting firm provides assistance to people who prepare their own tax returns. Their charges are as follows:

 If a person has low income (<= 25,000) and the consulting time is less than or equal to 30 minutes, there are no charges; otherwise, the service charges are 40% of the regular hourly rate for the time over 30 minutes.

 For others, if the consulting time is less than or equal to 20 minutes, there are no service charges; otherwise, service charges are 70% of the regular hourly rate for the time over 20 minutes.
 
 Write a program that prompts the user to enter the hourly rate, the total consulting time, and whether the person has low income. The program should output the billing amount. Your program must contain a function that takes as input the hourly rate, the total consulting time, and a value indicating whether the person has low income. The function should return the billing amount. Your program may prompt the user to enter the consulting time in minutes.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

double billAmount(double hourlyRate, double consultingTime, char lowIncome){
    if(lowIncome == 'Y'){
        if (consultingTime <= 30){
            return 0;
        }else {
            double hours = (consultingTime - 30) / 60;
            double rate = 0.4 * hourlyRate;
            return hours * rate;
        }
    }else {
        if(consultingTime <=20){
            return 0;
        }else{
            double hours = (consultingTime - 20) / 60;
            double rate = 0.7 * hourlyRate;
            return  hours * rate;
        }
    }
}

int main() {
    double hourlyRate, consultingTime;
    char lowIncome;
    
    cout << "Enter the hourly rate.\n";
    cin >> hourlyRate;
    cout << "Enter the consulting timem.\n";
    cin >> consultingTime;
    cout << "Does this person have low income? (Y/N)\n";
    cin >> lowIncome;
    lowIncome = toupper(lowIncome);
    
    double bill = billAmount(hourlyRate,consultingTime,lowIncome);
    
    printf("\nYour bill will be $%.2f\n", bill);
    
    return 0;
}
