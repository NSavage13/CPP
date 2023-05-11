//
//  main.cpp
//  apartment
//
//  Created by Nico Savage on 5/4/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>


using namespace std;

int main() {
    double rent = 600, units = 50;
    const double maintenance = 27;
    double prevProfit = 0, newProfit = 0;
    
    do{
        
        prevProfit = newProfit; // hold onto the last profit
        units -= 1;
        rent += 40;
        newProfit = (rent - maintenance) * units;
        
        cout << units << " prev " << prevProfit << " new profit " << newProfit << endl;
        
    }while(prevProfit < newProfit);
    // while loop does one extra iteration
    units += 1;
    rent -= 40;
    cout << "Max Profit!!" << endl;
    cout << "Units : " << units << endl;
    cout << "Rent : $" << rent << endl;
    cout << "Profit : " << prevProfit << endl;
    return 0;
}
