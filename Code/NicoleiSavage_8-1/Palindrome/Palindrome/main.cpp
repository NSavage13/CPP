//
//  main.cpp
//  Palindrome
//
//  Created by Nico Savage on 6/1/23.
/*
 A palindrome is a word that is the same when read normally and in reverse. Examples include radar, tacocat, and racecar. Enter a word. Walk through the word character by character. Place the characters into a stack and queue at the same time. Then use the stack and queues front, top, and pop methods to prove that the word is a palindrome.
 
 Ques - First in first out
      - push() - add to back
      - pop() - remove from front
      - front() - get front
      - empty() - check if empty
      - size() - get size
 */
#include <stack>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string word;
    queue<char> q;
    stack<char> s;
    bool isPalindrome = true;
    cout << "Enter a word: ";
    cin >> word;
    
    for (int i = 0; i < word.length(); i++) {
        q.push(word[i]);
        s.push(word[i]);
    }
    
    while (!q.empty() && isPalindrome) {
        if (q.front() != s.top()) {
            isPalindrome = false;
        }
        q.pop();
        s.pop();
    }
    if (isPalindrome) {
        cout << word << " is a palindrome." << endl;
    } else {
        cout << word << " is not a palindrome." << endl;
    }
    
    return 0;

}
