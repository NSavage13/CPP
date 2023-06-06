//
//  main.cpp
//  PriorityQue
//
//  Created by Nico Savage on 6/6/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <queue>

#include "helpTicket.hpp"

using namespace std;

void fillPQueue(priority_queue<int> &);
void printIntQueue(priority_queue<int>);

int main(int argc, const char * argv[]) {
    priority_queue<int> intpQueue;
    fillPQueue(intpQueue);
    printIntQueue(intpQueue);
    
}

void fillPQueue(priority_queue<int> & pQueue){
    int input = 0;
    string stringInput;
    do{
        cout << "Enter a number to add to the queue: ";
        //cin >> input;
        getline(cin, stringInput);
        try{
            input = stoi(stringInput);
            if(input > 0){
                pQueue.push(input);
            }
        }catch(exception e){
            input = 100;// just to make sure we don't get stuck in the loop with a string
        }
        
    }while(input > 0);
    cout << pQueue.size() << " elements in the queue."<< endl;
}

void printIntQueue(priority_queue<int> pQueue){
    int node;
    
    while(!pQueue.empty()){
        node = pQueue.top();
        cout << node << endl;
        pQueue.pop();
    }

//    while(!pQueue.empty()){
//        cout << pQueue.top() << endl;
//        pQueue.pop();
//    }
}

