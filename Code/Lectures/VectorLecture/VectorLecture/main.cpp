//
//  main.cpp
//  VectorLecture
//
//  Created by Nico Savage on 5/9/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void fillIntVector(vector<int> &vect){
    string input;
    int value;
    do{
        cout << "Enter a number, type QUIT when done --> ";
        cin >> input;
        
        try{
            value = stoi(input);
        }catch (invalid_argument eroor){
            // handle the error
            if (input != "QUIT"){
                cout << input << " is invalid, converting to 0\n";
            }
            value = 0;
        }
        vect.push_back(value);
    }while(input != "QUIT");
    vect.pop_back(); // removes the QUIT 0 when you exit;
}

void displayIntVector(vector<int> vect){
    vector<int>::iterator aNum;
    for(aNum = vect.begin(); aNum != vect.end(); aNum ++){
        cout << *aNum << " "; // * says give me the data in the memory location
    }
    
}

void displayIntVectorReverse(vector<int> vect){
    vector<int>::reverse_iterator aNum;
    // add the (r)begin and (r)end FOR REVERSE
    for(aNum = vect.rbegin(); aNum != vect.rend(); aNum ++){
        cout << *aNum << " "; // * says give me the data in the memory location
    }
    
}

int main() {
    
    vector<int> myVector = {1, 2, 3, 4};
    vector<string> words;
    
    array<double, 1000> myArray;
    
    fillIntVector(myVector);
    
    sort(myVector.begin(), myVector.end());
    
    displayIntVector(myVector);
    displayIntVectorReverse(myVector);
    
    words.push_back("Hello"); // put something into a vector
   // cout << words.at(0) << endl;
    words.pop_back(); // remove from the list
    
    return 0;
}
