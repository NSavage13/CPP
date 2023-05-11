//
//  main.cpp
//  ch7ex8
//
//  Created by Nico Savage on 5/3/23.
//
/*
 Write a program that reads in a line consisting of a student’s name, Social Security number, user ID, and password. The program outputs the string in which all the digits of the Social Security number and all the characters in the password are replaced by x. (The Social Security number is in the form 000-00-0000, and the user ID and the password do not contain any spaces.) Your program should not use the operator [] to access a string element. Use the appropriate functions described in Table 7-1.
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string firstName, lastName, username, password, socialSec;
    ifstream fin;
    fin.open("student.txt");
    if(fin.fail()){
        cout << "student" << " did not open\n";
        exit(1);
    }
    fin >> firstName >> lastName >> socialSec >> username >> password;
    socialSec.replace(0, 12, "000-00-0000");
    password.replace(password.begin(), password.end(),password.size(), 'x');
    
    cout <<"\n"<<firstName<<" "<<lastName<<" "<<socialSec<<" "<<username<<" "<<password<<"\n"<<endl;
    
    return 0;
}
