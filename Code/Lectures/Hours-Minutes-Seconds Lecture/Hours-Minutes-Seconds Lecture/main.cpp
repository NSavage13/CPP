//
//  main.cpp
//  Hours-Minutes-Seconds Lecture
//
//  Created by Nico Savage on 4/19/23.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int seconds=0,minutes=0,hours=0;
    //int const SECINHOUR = 60 * 60;
    int const CONVERT = 60;
    
    
    
    cout<< "Enter the number of seconds\n";
    cin >> seconds;
    cout << "You entered " << seconds << " seconds" << endl;
    
    hours = seconds / (CONVERT * CONVERT);
    seconds = seconds % (CONVERT * CONVERT);
    
    minutes = seconds / CONVERT;
    seconds = seconds % CONVERT;
    
    // setw sets the answer to two digits with (2)
    // SETFILL sets any empty space with the ('O')
    cout << hours << ":"<< setfill('0') << setw(2) << minutes<< ":" << setfill('0') << setw(2) << seconds << endl;
    
    
    
    
}
    
