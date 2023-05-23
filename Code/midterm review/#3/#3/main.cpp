//
//  main.cpp
//  #3
//
//  Created by Nico Savage on 5/15/23.
/*
 Create a function that searches the array for a number. If found, it returns the position of the number in the array. If not found, it return -1.
 Prove in main that both functionalities work.

 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;



int main(int argc, const char * argv[]) {
        
        int array[10] = {1,2,3,4,5,6,7,8,9,10};
        int search;
        int position = -1;
        
        cout << "Enter a number to search for: ";
        cin >> search;
        
        for (int i = 0; i < 10; i++) {
            if (array[i] == search) {
                position = i;
            }
        }
        
        if (position == -1) {
            cout << "The number " << search << " was not found in the array." << endl;
        } else {
            cout << "The number " << search << " was found in position " << position << " of the array." << endl;
        }
        
        return 0;
    
}
