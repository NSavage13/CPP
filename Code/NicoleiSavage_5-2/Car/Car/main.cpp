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

void carOperations(Car& car1,Car& car2);
void carComparisons(Car& car1,Car& car2);
void hybridComparisons(Hybrid& h1, Hybrid& h2);
int main() {
    Car car1;
    car1.setMake("Honda");
    car1.setModel("Civic");
    car1.setYear(2022);
    car1.setMiles(10000.0);
    car1.setGallons(10.0);
    car1.setMpg(35.0);
    Car car2 = Car("Toyota", "Corolla", 2005, 5500.3, 8, 52);
    cout <<"Car 1\n"<< car1 << endl;
    cout <<"Car 2\n"<< car2 << endl;
    carOperations(car1, car2);
    carComparisons(car1, car2);
    
    Car car3;
//    cin >> car3;
//    cout << car3 << endl;
    
    Hybrid hybrid1("Tesla", "Model 3", 2023, 1000, 8, 75, 100, 50);
    Hybrid hybrid2;
    cin >> hybrid2;
    cout << endl;
    cout <<"Hybrid 1\n"<< hybrid1 << endl;
    cout <<"Hybrid 2\n"<< hybrid2 << endl;
    hybridComparisons(hybrid1, hybrid2);

    
}
void hybridComparisons(Hybrid& h1, Hybrid& h2){
    if(h1 == h2){
        cout << "Hybrid 1 has the same charge percent as Hybrid 2" << endl;
    }
    if(h1 != h2){
        cout << "Hybrid 1 does not have the same charge percent as Hybrid 2" << endl;
    }
}
void carOperations(Car& car1,Car& car2){
    car1 = car1-car2;
    cout << "Car 1 year: "<< car1.getYear() << endl;
    car1 = car1+car2;
    cout << "Car 1 year: "<< car1.getYear() << endl;
    car1 = car1*car2;
    cout << "Car 1 year: "<< car1.getYear() << endl;
    car1 = car1/car2;
    cout << "Car 1 year: "<< car1.getYear() << endl;
    car1++;
    cout << "Car 1 year: "<< car1.getYear() << endl;
    ++car1;
    cout << "Car 1 year: "<< car1.getYear() << endl;
}
void carComparisons(Car& car1,Car& car2) {
    if (car1 < car2) {
        cout << "Car 1 is older than Car 2" << endl;
    }
    if (car1 > car2) {
        cout << "Car 1 is newer than Car 2" << endl;
    }
    if (car1 <= car2) {
        cout << "Car 1 is either older or the same as Car 2" << endl;
    }
    if (car1 >= car2) {
        cout << "Car 1 is either newer or the same as Car 2" << endl;
    }
    if (car1 == car2) {
        cout << "Car 1 is equal to Car 2" << endl;
    }
    if (car1 != car2) {
        cout << "Car 1 is not equal to Car 2" << endl;
    }
    cout << endl;
}
