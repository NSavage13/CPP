//
//  main.cpp
//  StackProblem
//
//  Created by Nico Savage on 6/1/23.
/*
 Stack - Last in first out
       - Recent stuff is easier to access
       - Control access to the data
       - push() - add to top
       - pop() - remove from top
       - top() - get top
       - empty() - check if empty
       - size() - get size
 
 You can either read it line by line and display the lines in reverse order, or read it word by word and display the words in reverse.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>

using namespace std;
void readFile(string fName, stack<string> &s){
    ifstream fin;
    string line = "";
    fin.open("frost.txt");
    if(fin.fail()){
        cout << "frost" << " did not open\n";
        exit(1);
    }
    while(getline(fin, line)){
        s.push(line);
    }
    while(!s.empty()){
        cout << s.top() << endl;
        // after you grab the top, you need to pop it off or it will just repeat the same line.
        s.pop();
    }
    fin.close();
}

int main(int argc, const char * argv[]) {
    stack<string> s;
    readFile("frost.txt", s);
}
