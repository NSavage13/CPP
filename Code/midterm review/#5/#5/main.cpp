//
//  main.cpp
//  #5
//
//  Created by Nico Savage on 5/16/23.
/*
 Build a class called Line. Recall that geometry defines a line as two points.
 Data
 Double x1, y1, x2, y2.
 Build
 both constructors
 all setters/getters
 to_string
 Function that calculates slope
 Slope = (y1-y2)/(x1-x2)
 If x1 = x2 then slope is undefined

 */
#include "Triangle.hpp"
#include "Line.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>


using namespace std;





int main(int argc, const char * argv[]) {
    
    Line line1 = Line(6,1,28,3);
    Line line2 = Line();
    
    Triangle tri1 = Triangle(5, 7, 1, 3, -2, -5);
    Triangle tri2 = Triangle();
    Line* arrayLine[3] = {&line1,&line2,&tri1};
    ofstream fout;
    string line = "";
    fout.open("output.txt");
    if(fout.fail()){
        cout << "student" << " did not open\n";
        exit(1);
    }

    ifstream fin;
    fin.open("input.txt");
    if(fin.fail()){
        cout << "File" << " did not open\n";
        exit(1);
    }
    while(getline(fin,line)){
        fout << line << endl;
    }
    cout << endl;
    fin.close();
    
    for(int i=0;i<size(arrayLine);i++){
        cout << arrayLine[i]->toString() << endl;
    }
    
    
    
    return 0;

    
    
    

}
