//
//  main.cpp
//  ch8ex6
//
//  Created by Nico Savage on 5/2/23.
//
/*
 The history teacher at your school needs help in grading a True/False test. The students’ IDs and test answers are stored in a file. The first entry in the file contains answers to the test in the form:

 Details
 Program code. In the code, the words in the variable names are merged. Line 1: T F F T F F T T T T F F T F T F T F T T.
 
 indicates that the student ID is ABC54301 and the answer to question 1 is True, the answer to question 2 is False, and so on. This student did not answer question 9. The exam has 20 questions, and the class has more than 150 students. Each correct answer is awarded two points, each wrong answer gets one point deducted, and no answer gets zero points. Write a program that processes the test data. The output should be the student’s ID, followed by the answers, followed by the test score, followed by the test grade. Assume the following grade scale: 90%–100%, A; 80%–89.99%, B; 70%–79.99%, C; 60%–69.99%, D; and 0%–59.99%, F.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string studentAnswer;
    string answers, studentID;
    ifstream fin;
    string line = "";
    fin.open("data.txt");
    if(fin.fail()){
        cout << "student" << " did not open\n";
        exit(1);
    }
    getline(fin, answers);
    
    while(getline(fin, line)){
        //cout << line << "  \n";
        studentID = line.substr(0,8);
        studentAnswer = line.substr(9,line.size());
        
        
        int score = 0;
        for (int i=0; i < answers.length();i++){
            if (studentAnswer[i] == ' '){
                score += 0;
            }else if(studentAnswer[i] == answers[i]){
                score += 2;
            }else {
                score -=1;
            }
        }
 //The output should be the student’s ID, followed by the answers, followed by the test score, followed by the test grade. Assume the following grade scale: 90%–100%, A; 80%–89.99%, B; 70%–79.99%, C; 60%–69.99%, D; and 0%–59.99%, F.
        double percent = ((double) score / 40) * 100;
        
        char grade;
        if (percent >= 90){
            grade = 'A';
        }else if(percent >= 80 && percent < 90){
            grade = 'B';
        }else if(percent >= 70 && percent < 80){
            grade = 'C';
        }else if(percent >= 60 && percent < 70){
            grade = 'D';
        }else {
            grade = 'F';
        }
        
        cout << "Student ID: " << studentID << " Student Answers: " << studentAnswer << " Score: " << score << " Grade: " << grade << endl;
    }
    
    
    return 0;
}
