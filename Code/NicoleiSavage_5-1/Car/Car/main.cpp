//
//  main.cpp
//  5-1
//
//  Created by Nico Savage on 5/9/23.
//

//.cpp (Implements)call it .h (declares)returns
#include "Car.hpp"
#include "Hybrid.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;




int main() {
    Car car1;
    car1.setMake("Honda");
    car1.setModel("Civic");
    car1.setYear(2022);
    car1.setMiles(10000.0);
    car1.setGallons(10.0);
    car1.setMpg(35.0);
    cout << car1.to_string() << endl;
    
    Hybrid hybrid1("Tesla", "Model 3", 2023, 1000, 8, 75, 100, 50);
    cout << hybrid1.to_string() << endl;
    hybrid1.chargeBattery(40.4);
    cout << hybrid1.to_string() << endl;

    
}
