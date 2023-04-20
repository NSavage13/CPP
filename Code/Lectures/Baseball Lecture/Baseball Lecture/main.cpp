//
//  main.cpp
//  Baseball Lecture
//
//  Created by Nico Savage on 4/19/23.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define WID setw(10)
using namespace std;

int main() {
    ifstream fin;
    int number, atbats, hits, walks;
    float batAvg = 0;
    
    fin.open("baseball.txt");
    
    if(fin.fail()){
        cout << "File did not open";
        exit(1);// kills program
    }
    cout << WID << "Number" << WID << "Bat Avg" << endl;
    while (true){
        fin >> number >> atbats >> hits >> walks;
        //cout << number << " " << atbats << " " << hits << " " << walks << endl;
        if (atbats == walks) {
            batAvg = 0;
        }else {
            batAvg = hits / static_cast<float>(atbats - walks);
        }
        if (!fin.eof()){
            cout << setprecision(3)<< fixed;
            cout << setw(10) << number << setw(10) << batAvg<< endl;
        }else {
            break;
        }
        
    }
    
    
}
