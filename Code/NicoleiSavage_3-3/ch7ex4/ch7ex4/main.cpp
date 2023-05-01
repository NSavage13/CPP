//
//  main.cpp
//  ch7ex4
//
//  Created by Nico Savage on 4/26/23.
//
/*
 Write a program that prompts the user to input a string. The program then uses the function substr to remove all the vowels from the string. For example, if str = "There", then after removing all the vowels, str = "Thr". After removing all the vowels, output the string. Your program must contain a function to remove all the vowels and a function to determine whether a character is a vowel.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

bool checkVowels(char c){
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void removeVowels(string str){
    string notVowel;
    for(int i = 0;i < str.length() ;i++){
        if(!checkVowels(str[i])){
            notVowel += str[i];
        }
    }
    cout << notVowel << endl;
}
int main() {
    string str;
    cout << "Enter any string.\n";
    getline(cin, str);
    removeVowels(str);
    
    return 0;
}
