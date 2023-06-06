//
//  main.cpp
//  HelpRequest
//
//  Created by Nico Savage on 6/6/23.
/*
 A teacher has a problem. There are many students waiting at their desk for help. To simplify their life, they want a queue. The student puts their name into the queue, and is told their position in the queue. When ready, the teacher pulls the next student from the queue and helps them.

 Build a simple interface for this queue. Make it menu driven
 student can enter their name in the queue
 the teacher can get a student from the queue
 close the program
 Do not let the program close if the queue is not empty!
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    queue<string> helpQueue;
    int choice = 0;
    string name;
    do {
        cout << "1. Add student to queue" << endl;
        cout << "2. Get next student from queue" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            helpQueue.push(name);
            cout << name << " is number " << helpQueue.size() << " in the queue.\n" << endl;
        } else if (choice == 2) {
            if (helpQueue.empty()) {
                cout << "No students in queue." << endl;
            } else {
                cout << helpQueue.front() << " is next in the queue.\n" << endl;
                helpQueue.pop();
            }
        }
        if (choice == 3 && !helpQueue.empty()) {
            cout << "Cannot quit with students in queue.\n" << endl;
            choice = 0;
        }
    } while (choice != 3 || !helpQueue.empty());

    
}
