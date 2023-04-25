//
//  main.cpp
//  ch5-ex4
//
//  Created by Nico Savage on 4/20/23.
/**
 To make telephone numbers easier to remember, some companies use letters to show their telephone number. For example, using letters, the telephone number 438-5626 can be shown as GET LOAN. In some cases, to make a telephone number meaningful, companies might use more than seven letters. For example, 225-5466 can be displayed as CALL HOME, which uses eight letters. Write a program that prompts the user to enter a telephone number expressed in letters and outputs the corresponding telephone number in digits. If the user enters more than seven letters, then process only the first seven letters. Also output the - (hyphen) after the third digit. Allow the user to use both uppercase and lowercase letters as well as spaces between words. Moreover, your program should process as many telephone numbers as the user wants.
 */

#include <iostream>
#include <string>

using namespace std;

string getPhoneNumber(string letters) {
    string phoneNumber = "";
    int counter = 0;

    for (char c : letters) {
        c = toupper(c); // Convert the character to uppercase
        if (isalpha(c)) {
            if (counter == 3) {
                phoneNumber += '-'; // Add hyphen after third digit
            }
            if (c >= 'A' && c <= 'C') {
                phoneNumber += '2';
            } else if (c >= 'D' && c <= 'F') {
                phoneNumber += '3';
            } else if (c >= 'G' && c <= 'I') {
                phoneNumber += '4';
            } else if (c >= 'J' && c <= 'L') {
                phoneNumber += '5';
            } else if (c >= 'M' && c <= 'O') {
                phoneNumber += '6';
            } else if (c >= 'P' && c <= 'S') {
                phoneNumber += '7';
            } else if (c >= 'T' && c <= 'V') {
                phoneNumber += '8';
            } else if (c >= 'W' && c <= 'Z') {
                phoneNumber += '9';
            }
            counter++;
        }
        if (counter == 7) {
            break;
        }
    }

    return phoneNumber;
}

int main() {
    string input;
    char choice;

    do {
        cout << "Enter a telephone number expressed in letters: ";
        cin >> input;
        string phoneNumber = getPhoneNumber(input);
        cout << "The corresponding telephone number in digits: " << phoneNumber << endl;
        cout << "Do you want to process another telephone number? (Y/N): ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
    
    return 0;
}
