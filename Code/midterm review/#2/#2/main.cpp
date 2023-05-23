//
//  main.cpp
//  #2
//
//  Created by Nico Savage on 5/15/23.
/*
 Create a function that returns the range of the numbers in the array. Range is the max minus the min.
 Do not display in the function. Display the returned value in main.

 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;



int main(int argc, const char * argv[]) {
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int max = array[0];
    int min = array[0];
    int range;
    
    
    for (int i = 0; i < 10; i++) {
        if (array[i] > max) {
            max = array[i];
            
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    
    range = max - min;
    
    cout << "The range of the array is " << range << endl;
    
    return 0;

}
