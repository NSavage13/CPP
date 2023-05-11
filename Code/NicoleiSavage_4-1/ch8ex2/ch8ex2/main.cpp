//
//  main.cpp
//  ch8ex2
//
//  Created by Nico Savage on 5/1/23.
//
/*
 Write a C++ function, smallestIndex, that takes as parameters an int array and its size and returns the index of the first occurrence of the smallest element in the array. Also, write a program to test your function.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
int in;
int smallestIndex(int arr[], int size){
    int smallest = arr[0];
    for (int i = 0;i < size;i++){
        if (arr[i] < smallest){
            smallest = arr[i];
            in = i;
        }
    }
    return smallest;
    }
int main() {
    int arr[] = {12, 15, 17 ,-3, -3, 5, 6};
    /*
     int = 4bytes
     sizeof returns (4-bytes) * (number of elements in array).
     Divide by any index to get size.
     */
    int size = sizeof(arr) / sizeof(arr[0]);
    int small = smallestIndex(arr, size);
    cout <<"The smallest number is " << small << " at index " << in << endl;
    return 0;
}
