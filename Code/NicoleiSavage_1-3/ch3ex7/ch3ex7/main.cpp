// 
//  main.cpp
//  ch3ex7
//
//  Created by Nico Savage on 4/18/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double netBalance, payment, intRate;
    int d1, d2;
    
    cout << "What is your net balance?\n";
    cin >> netBalance;
    cout << "What is your payment?\n";
    cin >> payment;
    cout << "What is the number of days in the billing cycle?\n";
    cin >> d1;
    cout << "What is the number of days the payment was made before billing cycle?\n";
    cin >> d2;
    cout << "What is your interest rate?\n";
    cin >> intRate;
    
    double aveDayBalance = (netBalance * d1 - payment * d2)/d1;
    double interest = aveDayBalance * intRate;
    
//    cout.precision(4);
    cout << "Your interest will be ";
    printf("%.2f", interest);
    cout << "\n";
    
    
    
    return 0;
}
