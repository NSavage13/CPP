//
//  main.cpp
//  ch4ex6
//
//  Created by Nico Savage on 4/20/23.
//
//A box of cookies can hold 24 cookies, and a container can hold 75 boxes of cookies. Write a program that prompts the user to enter the total number of cookies, the number of cookies in a box, and the number of cookie boxes in a container. The program then outputs the number of boxes and the number of containers to ship the cookies. Note that each box must contain the specified number of cookies, and each container must contain the specified number of boxes. If the last box of cookies contains less than the number of specified cookies, you can discard it and output the number of leftover cookies. Similarly, if the last container contains less than the number of specified boxes, you can discard it and output the number of leftover boxes.

#include <iostream>
using namespace std;

int main() {
    int totalCookies, cookiesPerBox=24, boxesPerContainer=75;
    
    cout << "Enter the total number of cookies: ";
    cin >> totalCookies;
    
    int boxesNeeded = totalCookies / cookiesPerBox;
    int containersNeeded = boxesNeeded / boxesPerContainer;

    int leftoverBoxes = boxesNeeded % boxesPerContainer;
    int leftoverCookies = totalCookies % cookiesPerBox;

    if (leftoverBoxes > 0) {
        containersNeeded++;
        leftoverBoxes = boxesPerContainer - leftoverBoxes;
    }

    if (leftoverCookies > 0) {
        leftoverCookies = cookiesPerBox - leftoverCookies;
    }

    cout << "Number of boxes needed: " << boxesNeeded << endl;
    cout << "Number of containers needed: " << containersNeeded << endl;
    cout << "Number of leftover boxes: " << leftoverBoxes << endl;
    cout << "Number of leftover cookies: " << leftoverCookies << endl;

    return 0;


}
