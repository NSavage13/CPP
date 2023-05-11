//
//  main.cpp
//  ch8ex13
//
//  Created by Nico Savage on 5/4/23.
//
/*
 Write a program to calculate students’ average test scores and their grades. You may assume the following input data:
 Use three arrays: a one-dimensional array to store the students’ names, a (parallel) two-dimensional array to store the test scores, and a parallel one-dimensional array to store grades. Your program must contain at least the following functions: a function to read and store data into two arrays, a function to calculate the average test score and grade, and a function to output the results. Have your program also output the class average.
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
const int numStudents = 10;
const int numTest = 5;

string names[numStudents];
int scores[numStudents][numTest];
char grades[numStudents];
void readFile(string fn);
void calculateAverage();
void results();


int main() {
    readFile("ch8ex13Data.txt");
    calculateAverage();
    results();
    return 0;
}

//----------------------------------------------------------------

void readFile(string fn){
    ifstream fin;
    string line = "";
    fin.open(fn);
    if(fin.fail()){
        cout << fn << " did not open\n";
        exit(1);
    }
    
    for (int i=0; i < numStudents; i++){
        fin >> names[i];
        for (int k=0;k<numTest;k++){
            fin >> scores[i][k];
        }
        
    }
    fin.close();
}

//----------------------------------------------------------------

void calculateAverage() {
    double totalScores = 0;
    for (int i = 0; i < numStudents; i++) {
        double sum = 0;
        for (int k = 0; k < numTest; k++) {
            sum += scores[i][k];
        }
        double average = sum / numTest;
        if(average >= 90){
            grades[i] = 'A';
        }else if(average >= 80){
            grades[i] = 'B';
        }else if(average >= 70){
            grades[i] = 'C';
        }else if(average >= 60){
            grades[i] = 'D';
        }else{
            grades[i] = 'F';
        }
        totalScores += sum;
    }
    double classAverage = totalScores / (numStudents * numTest);
    cout << "Class average: " << classAverage << "%"<< endl;
}

//----------------------------------------------------------------

void results(){
    for (int i = 0; i < numStudents; i++) {
        cout << names[i] << " ";
        for (int j = 0; j < numTest; j++) {
            cout << scores[i][j] << " ";
        }
        cout << grades[i] << endl;
    }
}
