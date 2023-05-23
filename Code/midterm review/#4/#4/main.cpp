//
//  main.cpp
//  #4
//
//  Created by Nico Savage on 5/16/23.
/*
 Write the array out to a file. Put the array on one line with a comma and space between the numbers.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;




int main(int argc, const char * argv[]) {
    
    int array[10];
    ofstream outputFile;
    
    outputFile.open("arrays.txt");
    
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
        outputFile << array[i] << ", ";
    }
    
    outputFile.close();
    
    
    
    
    
    
    return 0;

}
