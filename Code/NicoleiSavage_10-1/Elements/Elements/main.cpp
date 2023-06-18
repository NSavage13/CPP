//
//  main.cpp
//  Elements
//
//  Created by Nico Savage on 6/15/23.
/*
 Build a class to hold all the data in the file

 Read the file into a map of the class. Use the Symbol as the key.

 Create an interface that allows the user to enter a symbol and the information about the element is displayed in a nice format. The user can continue to enter symbols until they are tired of chemistry.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Elements {
public:
    string name;
    string symbol;
    int atomicNumber;
    double atomicWeight;
    string dens;
    double meltingPoint;
    double boilingPoint;
    double atomicRadius;
    string title[8]= {"Name", "Symbol", "Atomic Number", "Atomic Weight", "Density" ,"Melting Point", "Boiling Point", "Atomic Radius"};
    
    Elements() {
        name = "";
        symbol = "";
        atomicNumber = 0;
        atomicWeight = 0;
        dens = "";
        meltingPoint = 0;
        boilingPoint = 0;
        atomicRadius = 0;
    
    }
    Elements(const string& name,const string& symbol, int atomicNumber, double atomicWeight, const string& dens,
            double meltingPoint, double boilingPoint, double atomicRadius)
        : name(name),symbol(symbol), atomicNumber(atomicNumber),atomicWeight(atomicWeight), dens(dens),
          meltingPoint(meltingPoint), boilingPoint(boilingPoint),
          atomicRadius(atomicRadius){}

    
//    Element(const string& name,string& symbol, int atomicNumber, double atomicWeight, string& dens,
//            double meltingPoint, double boilingPoint, double atomicRadius)
//        : name(name),symbol(symbol), atomicNumber(atomicNumber),atomicWeight(atomicWeight), dens(dens),
//          meltingPoint(meltingPoint), boilingPoint(boilingPoint),
//          atomicRadius(atomicRadius){}

    
    void displayInfo() const {
        const int setTheWidth = 20;
        cout << left;
        for (int i = 0; i < 8; i++) {
            cout << setw(setTheWidth) << title[i] << " | ";
        }
        cout << endl;
        for (int i = 0; i < 8; i++) {
            cout << "---------------------|-";
        }
        cout << endl;
        cout << setw(setTheWidth) << name << " | ";
        cout << setw(setTheWidth) << symbol << " | ";
        cout << setw(setTheWidth) << atomicNumber << " | ";
        cout << setw(setTheWidth) << atomicWeight << " | ";
        cout << setw(setTheWidth) << dens << " | ";
        cout << setw(setTheWidth) << meltingPoint << " | ";
        cout << setw(setTheWidth) << boilingPoint << " | ";
        cout << setw(setTheWidth) << atomicRadius << " | ";
        cout << endl;
    }
};




int main() {
    Elements element("Hydrogen","H", 1, 1.008, "0.0708 (@ -253degC)" ,-259.1, -252.9, 37.0);
    element.displayInfo();
    
    map<string, Elements> elements;
    ifstream fin;
    string line = "";
    fin.open("elementdata.txt");
    if(fin.fail()){
        cout << "student" << " did not open\n";
        exit(1);
    }
    while (getline(fin, line)) {
        stringstream ss(line);
        string name;
        string symbol;
        int atomicNumber;
        double atomicWeight;
        string dens;
        double meltingPoint;
        double boilingPoint;
        double atomicRadius;
        string temp;
        
        if (ss >> name >> symbol >> atomicNumber >> atomicWeight >> dens >> meltingPoint){
            
            if (meltingPoint < 0){
                ss >> dens;
                ss >> meltingPoint;
            }
            
            ss >> boilingPoint >> atomicRadius;
            Elements element(name, symbol, atomicNumber, atomicWeight, dens, meltingPoint, boilingPoint, atomicRadius);
            elements[symbol] = element;
        }
        cout << endl;
        
        string inputSymbol;
        cout << "Enter an element symbol: ";
        cin >> inputSymbol;
        
        auto it = elements.find(inputSymbol);
        if (it != elements.end()) {
            const Elements& element = it->second;
            element.displayInfo();
        } else {
            cout << "Element not found." << endl;
        }
    }
    
}
