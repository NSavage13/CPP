//
//  main.cpp
//  Week 3
//
//  Created by Nico Savage on 5/3/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;


//----------------------------------------------------------------------------------------

void parseFiles(string path, int letters[], int &numWords, int &numLines, int &numLetters);
// Do not see (&) sign because this method does not change the values just shows the.
void showCounts(int letters[], int numWords, int numLetters, int numLines);
void countLetters(string line, int letters[], int &numLetters);

void countWords(string line, int &numWords);

//----------------------------------------------------------------------------------------

int main() {
    int numLetter = 0;
    int numWords = 0;
    int numLines = 0;
    int letters[26];
    
    for(int x=0;x < 26; x++){
        letters[x] = 0;
    }
    
    parseFiles("/Users/nicosavage/Desktop/CPP/Code/Lectures/Week 3/frost.txt", letters, numWords, numLines, numLetter);
    showCounts(letters, numWords, numLetter, numLines);
    
    return 0;
}

//----------------------------------------------------------------------------------------

void countWords(string line, int &numWords){
    char *token;
    
    char *cstr = new char[line.length() + 1];
    // cstr = converted string
    strcpy(cstr, line.c_str());
    token = strtok(cstr, " ");
    
    while(token != NULL){
        numWords ++;
        token = strtok(NULL, " ");
    }
    
}

//----------------------------------------------------------------------------------------

void countLetters(string line, int letters[], int &numLetters){
    char let;
    for(int c = 0; c < line.length(); c++){
        let = toupper(line.at(c));
        
        if (let >=65 && let <= 90){
            letters[let - 65]++;
            numLetters ++;
        }
    }
}

//----------------------------------------------------------------------------------------

void showCounts(int letters[], int numWords, int numLetters, int numLines){
    for(int let ='A'; let <= 'Z'; let++){
        cout << left << setw(10) << let << right << setw(6) << static_cast<char>(let) << endl;

    }
    cout << left << setw(10) << "Lines " << right << setw(6) << numLines << endl;
    cout << left << setw(10) << "Words " << right << setw(6) << numWords << endl;
    cout << left << setw(10) << "Letters " << right << setw(6) << numLetters << endl;
}

//----------------------------------------------------------------------------------------

void parseFiles(string path, int letters[], int &numWords, int &numLines, int &numLetters){
    ifstream fin;
    string line = "";
    fin.open(path);
    if(fin.fail()){
        cout << path << " did not open\n";
        exit(1);
    }
    while(getline(fin, line)){
        countLetters(line, letters, numLetters);
        numLines++;
        countWords(line, numWords);
        
    }
    fin.close();
}

