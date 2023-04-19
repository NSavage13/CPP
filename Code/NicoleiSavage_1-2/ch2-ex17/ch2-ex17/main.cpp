//
//  main.cpp
//  ch2-ex17
//
//  Created by Nico Savage on 4/18/23.
//

#include <iostream>
using namespace std;
int main() {
    double liters;
    double cost;
    double profit;
    cout << "Enter the amount of milk in liters produced this morning\n";
    cin >> liters;
    cout << "Enter the cost of a producing a liter of milk\n";
    cin >> cost;
    cout << "Enter the profit you get per carton\n";
    cin >> profit;
    
    int cartons = liters / 3.78;
    cost = cost * liters;
    profit = cartons * profit;
    cout << "$" << cost << " is the cost of producing the milk\n";
    cout << "$" << profit << " is the profit from the milk\n";
    
    
}
