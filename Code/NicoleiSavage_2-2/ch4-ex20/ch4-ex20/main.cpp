//
//  main.cpp
//  ch4-ex20
//
//  Created by Nico Savage on 4/20/23.
//
/**
 The cost of renting a room at a hotel is, say $100.00 per night. For special occasions, such as a wedding or conference, the hotel offers a special discount as follows: If the number of rooms booked is at least 10, the discount is 10%; at least 20, the discount is 20%; and at least 30, the discount is 30%. Also if rooms are booked for at least three days, then there is an additional 5% discount. Write a program that prompts the user to enter the cost of renting one room, the number of rooms booked, the number of days the rooms are booked, and the sales tax (as a percent). The program outputs the cost of renting one room, the discount on each room as a percent, the number of rooms booked, the number of days the rooms are booked, the total cost of the rooms, the sales tax, and the total billing amount. Your program must use appropriate named constants to store special values such as various discounts.
 */

#include <iostream>
using namespace std;

const double TEN_PERCENT_DISCOUNT = 0.10;
const double TWENTY_PERCENT_DISCOUNT = 0.20;
const double THIRTY_PERCENT_DISCOUNT = 0.30;
const double THREE_DAY_DISCOUNT = 0.05;

int main() {
    double discountRate = 0.0;
    double costPerRoom = 100.00, salesTax = 0.05, cost;
    int numOfRooms = 12;
    int numOfDays = 3;
    
    cout << "Enter the cost per room >> ";
    cin >> costPerRoom;
    cout << "Enter the number of rooms booked >> ";
    cin >> numOfRooms;
    cout << "Enter thee number of days the rooms are booked >> ";
    cin >>numOfDays;
    cout <<"Enter the sales tax rate >> ";
    cin >> salesTax;
    if (numOfRooms>=30){
        discountRate = THIRTY_PERCENT_DISCOUNT;
    }else if (numOfRooms>=20){
        discountRate = TWENTY_PERCENT_DISCOUNT;
    }else if (numOfRooms>=10){
        discountRate = TEN_PERCENT_DISCOUNT;
    }
    if (numOfDays>=3){
        discountRate += THREE_DAY_DISCOUNT;
    }
    
    cost = costPerRoom * numOfRooms * numOfDays;
    double discountAmount = cost * discountRate;
    double salesTaxAmount = cost * salesTax;
    double totalWithoutSalesTax = cost - discountAmount;
    double totalCost = totalWithoutSalesTax + salesTaxAmount;
    
    cout << "Cost of renting one room: $" << costPerRoom << endl;
    cout << "Discount on each room: " << (discountRate * 100) << "%" << endl;
    cout << "Number of rooms booked: " << numOfRooms << endl;
    cout << "Number of days the rooms are booked: " << numOfDays << endl;
    cout << "Total cost of the rooms: $" << totalWithoutSalesTax << endl;
    cout << "Sales tax: $" << salesTaxAmount << endl;
    cout << "Total billing amount: $" << totalCost << endl;
    
    
    
    return 0;
}
