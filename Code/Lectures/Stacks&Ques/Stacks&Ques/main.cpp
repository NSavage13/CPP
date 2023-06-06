//
//  main.cpp
//  Stacks&Ques
//
//  Created by Nico Savage on 6/5/23.
/*
 Stack - Last in first out
       - Recent stuff is easier to access
       - Control access to the data
       - push() - add to top
       - pop() - remove from top
       - top() - get top
       - empty() - check if empty
       - size() - get size
 
 Ques - First in first out
      - push() - add to back
      - pop() - remove from front
      - front() - get front
      - empty() - check if empty
      - size() - get size
 */
#include <stack>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

bool balancedExpression(string exp){
    // find a ( - put (push) on the stack
    // find a ) - pop off the stack
    // the pop should match the push
    // stack should be empty at the end
    stack<char> parents;
    for (char ch : exp){
        if (ch == '('){
            parents.push(ch);
        }
        if (ch == ')'){
            if (parents.empty()){
                return false;
            }
        char top = parents.top(); // take from the top of the stack
        parents.pop(); // remove from the top of the stack
        
            if (top == '(' && ch != ')'){
                return false;
            }
        }//end top if
    }//end for
    
    return parents.empty();

}

int main(int argc, const char * argv[]) {
    string exp = "((5-x)*(2+x))"; // balanced
    string exp2 = "((5-x)*(2+x)))"; // not balanced
    if (balancedExpression(exp)){
        cout << exp << " is Balanced" << endl;
    }
    else{
        cout << exp << " is not Balanced" << endl;
    }
}
