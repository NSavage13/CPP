//
//  main.cpp
//  ch3ex12
//
//  Created by Nico Savage on 4/18/23.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int carASpeed, carBSpeed, hours, minutes;
    double shortDistance;
    
    cout  << "Enter the average speed for car A\n";
    cin >> carASpeed;
    cout  << "Enter the average speed for car B\n";
    cin >> carBSpeed;
    
    cout << "Enter the amount of time in hours\n";
    cin >> hours;
    cout << "Enter the amount of time in minutes\n";
    cin >> minutes;
    
    double totalTime = hours + (minutes/60);
    
    int distanceA = carASpeed * totalTime;
    int distanceB = carBSpeed * totalTime;
    
    // Week 1 Lecture
    shortDistance = sqrt(pow(distanceA, 2) + pow(distanceB, 2));
    
    printf("The shortest distance between the two cars is %.2f miles.\n", shortDistance);
    
    return 0;
}
