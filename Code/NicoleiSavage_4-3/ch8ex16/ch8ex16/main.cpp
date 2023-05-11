//
//  main.cpp
//  ch8ex16
//
//  Created by Nico Savage on 5/4/23.
//
/*
 (Pick 5 Lotto) Write a program to simulate a pick-5 lottery game. Your program should generate and store 5 distinct numbers between 1 and 9 (inclusive) into an array. The program prompts the user to enter five distinct between 1 and 9 and stores the number into another array. The program then compares and determines whether the two arrays are identical. If the two arrays are identical, then the user wins the game; otherwise the program outputs the number of matching digits and their position in the array.

 Your program must contain a function that randomly generates the pick-5 lottery numbers. Also, in your program, include the function sequential search to determine if a lottery number generated has already been generated.
 */

//Need srand and a different parameter to generagte diiferent numbers.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
void userTicket();
void winningTicket();
void check(int a[], int win[]);

bool allMatch = true;
int winNumbers[5];
int userNumbers[5];

int main() {
    userTicket();
    winningTicket();
    check(userNumbers, winNumbers);
    if (allMatch == false){
        cout << "Loser.\n";
    }else {
        cout << "WINNER!\n";
    }
    

    return 0;
}

void winningTicket(){
    int ranNum;
    cout << "Winning Numbers: ";
    srand ((unsigned)time(NULL));
    for(int i=0;i < 5;i++){
        bool duplicate;
        do {
            duplicate = false;
            ranNum = rand()%9 + 1;
            for (int j = 0; j < i; j++) {
                if (winNumbers[j] == ranNum) {
                    duplicate = true;
                    break;
                }
            }
        } while (duplicate);
        winNumbers[i] = ranNum;
        cout << winNumbers[i];
    }
    cout << "\n";
}

void userTicket(){
    cout << "Pick five numbers (1-9).\n";
    for(int i=0;i < 5;i++){
            cin >> userNumbers[i];
        }
}

void check(int a[],int win[]){
    for(int i=0; i < 5;i++){
        if(a[i] != win[i]){
            allMatch = false;
            break;
        }
    }
    
}
// How do I check if the numbers are the same no matter what order.
