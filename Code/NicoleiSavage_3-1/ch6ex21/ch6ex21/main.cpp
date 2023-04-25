//
//  main.cpp
//  ch6ex21
//
//  Created by Nico Savage on 4/24/23.
//
/*
 Write a program that prints the day number of the year, given the date in the form month-day-year. For example, if the input is 1-1-2006, the day number is 1; if the input is 12-25-2006, the day number is 359. The program should check for a leap year. A year is a leap year if it is divisible by 4, but not divisible by 100. For example, 1992 and 2008 are divisible by 4, but not by 100. A year that is divisible by 100 is a leap year if it is also divisible by 400. For example, 1600 and 2000 are divisible by 400. However, 1800 is not a leap year because 1800 is not divisible by 400.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

bool isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dayNumber(int day, int month, int year){
    int dayNum = 0;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    
    for (int i = 1; i < month; i++){
        if(i == 2 && isLeapYear(year)){
            dayNum += 29;
        }else {
            dayNum += daysInMonth[i];
        }
    }
    dayNum += day;
    return dayNum;
}
int main() {
    int day, month, year;
    char delim;
    cout << "Enter the date in (MM-DD-YYYY) form.\n";
    cin >> month >> delim >> day >> delim >> year;
    
    int totalDays = dayNumber(day, month, year);
    cout << totalDays << endl;
    

    
    return 0;
}
