//
//  main.cpp
//  WordMemory
//
//  Created by Nico Savage on 5/25/23.
/*
 You want to create a program that asks users to enter words and store them in memory. Continue to store words until the user enters DONE. You want to ensure that the user cannot enter the same word twice, and you want the items sorted. Hint: This calls for the STL set class.
     --Display the words to the screen.
     --Display the number of words entered.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    string word;
    set<string> memory;
    
    cout << "Enter word. (Enter DONE to finish)" << endl;
    while(true){
        cin >> word;
        word[0] = toupper(word[0]);
        memory.insert(word);
        if(word == "DONE"){
            memory.erase("DONE");
            break;
        }
    }
    
    cout <<"~~Words in the memory~~\n";
    for(set<string>::iterator it = memory.begin(); it != memory.end(); ++it){
            cout << *it << ", ";
    }
        cout << "\n~~Number of words entered: " << memory.size() << endl;
        
        
        
    
}
    
    

