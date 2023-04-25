//
//  main.cpp
//  ch5ex33
//
//  Created by Nico Savage on 4/24/23.
//
//Bianca is preparing special dishes for her daughter’s birthday. It takes her a minutes to prepare the first dish, and each following dish takes b minutes longer than the previous dish. She has t minutes to prepare the dishes. For example, if the first dish takes a = 10 minutes and b = 5, then the second dish will take 15 minutes, the third dish will take 20 minutes, and so on. If she has 80 minutes to prepare the dishes, then she can prepare four dishes because 10 + 15 + 20 + 25 = 70. Write a program that prompts the user to enter the values of a, b, and t, and outputs the number of dishes Bianca can prepare.


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int a, b, t;
    int totalMinutes = 0, numDishes = 0;
    
    cout << "Enter the amount of minutes it take to make the FIRST dish. >> ";
    cin >> a;
    cout << "Enter the amount of minutes added for the following dishes. >> ";
    cin >> b;
    cout << "Enter the total amount of minutes available to prepare your dishes. >> ";
    cin >> t;
    
    while (totalMinutes <= t){
        numDishes ++;
        totalMinutes += a;
        
        a += b;
    }
    
    numDishes --;
    
    cout << "Bianca can prepare " << numDishes << " dishes." << endl;
    
    
    
    
    return 0;
}
