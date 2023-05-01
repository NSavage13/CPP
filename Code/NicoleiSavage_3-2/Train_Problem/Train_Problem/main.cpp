//
//  main.cpp
//  Train_Problem
//
//  Created by Nico Savage on 4/25/23.
//

#include <iostream>
#include <cmath>

using namespace std;

double velocity(double a, double t) {
    return a * t;
}

double howFar(double v1, double v2, double t) {
    return (v1 + v2) * t;
}

double timeTillCrash(double d, double v1, double v2) {
    return d / (v1 + v2);
}

int main() {
    double distanceBetweenCities = 262;
    double maxSpeedPittsburgh;
    double maxSpeedPhiladelphia;
    double accelerationPittsburgh;
    double accelerationPhiladelphia;
    
    double time = 0;
    double distance = 0;
    double velocityPittsburgh = 0;
    double velocityPhiladelphia = 0;
    
    cout << "Enter max speed for the Pittsburgh train.\n";
    cin >> maxSpeedPittsburgh;
    cout << "Enter max speed for the Philadelphia train.\n";
    cin >> maxSpeedPhiladelphia;
    cout << "Enter the acceleration rate for the Pittsburgh train.\n";
    cin >> accelerationPittsburgh;
    cout << "Enter the acceleration rate for the Philadelphia train.\n";
    cin >> accelerationPhiladelphia;
    
//    double accPitt = maxSpeedPittsburgh * accelerationPittsburgh;
//    double accPhil = maxSpeedPhiladelphia * accelerationPhiladelphia;
    
    /*
     Using a smaller time step (such as time += 0.001) will increase the precision of the simulation, but also increase the time it takes to run the simulation. Using a larger time step (such as time += 0.1) will decrease the precision, but make the simulation run faster.
     */
    while (distance < distanceBetweenCities) {
        time += 0.001;
        velocityPittsburgh = min(velocity(accelerationPittsburgh, time), maxSpeedPittsburgh);
        velocityPhiladelphia = min(velocity(accelerationPhiladelphia, time), maxSpeedPhiladelphia);
        distance = howFar(velocityPittsburgh, velocityPhiladelphia, time);
    }

    double Crashed = timeTillCrash(distanceBetweenCities, velocityPittsburgh, velocityPhiladelphia);
    printf("The two trains will crash after %.2f hours.\nPitt Velocity = %.2f\nPhil velocity = %.2f\n", Crashed, velocityPittsburgh, velocityPhiladelphia);

    return 0;
}


