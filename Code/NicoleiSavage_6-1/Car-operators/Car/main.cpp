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
    Car car1;car1.setMake("Honda");car1.setModel("Civic");car1.setYear(2022);car1.setMiles(10000.0);car1.setGallons(10.0);car1.setMpg(35.0);
    Car car2 = Car("Toyota", "Corolla", 2005, 5500.3, 8, 52);
    Hybrid hybrid1("Tesla", "Model 3", 2023, 1000, 8, 75, 100, 50);
    Hybrid hybrid2;
    Car cOper, cCompare;
    Hybrid hComapre;
    cCompare.carComparisons(car1, car2);
    cOper.carOperations(car1, car2);
    //cin >> hybrid2;
    hComapre.hybridComparisons(hybrid1, hybrid2);
}






