//
//  main.cpp
//  #5
//
//  Created by Nico Savage on 5/22/23.
//
#include "TreasureChest.hpp"
#include "MapCoordinate.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
MapCoordinate mc1 = MapCoordinate();
MapCoordinate mc2 = MapCoordinate("Location 1", 39.735, 42.131);
void inFile(string f);
void outFile(string f);

int main(int argc, const char * argv[]) {
    mc1.setName("Location 2");
    mc1.setLatitude(-56.345);
    mc1.setLongitude(87.321);
    cout << mc2 << endl;
    outFile("mc.txt");
    inFile("mc.txt");
    
    TreasureChest chest1 = TreasureChest();
    TreasureChest chest2 = TreasureChest("Treasure 2", 55.555, 78.432, "Golden Boot", "Jack Sparrow");
    TreasureChest chest3 = TreasureChest("Treasure 3", 40.987, -72.345, "Diamonds", "Calico Jack");

    TreasureChest chestArray[3] = {chest1,chest2,chest3};
    for(int i = 0;i < 3;i++){
        cout << chestArray[i] << endl;
    
    }
    
    
}

void inFile(string f){
    MapCoordinate mc3;
    ifstream fin;
    string line = "";
    fin.open(f);
    if(fin.fail()){
        cout << "mc" << " did not open\n";
        exit(1);
    }
    if (fin.is_open()) {
        string label;
        double value;

        getline(fin, label, ':');
        getline(fin, label, ' ');
        getline(fin, label);
        mc3.setName(label);

        getline(fin, label, ':');
        fin >> value;
        mc3.setLatitude(value);
        fin.ignore();

        getline(fin, label, ':');
        fin >> value;
        mc3.setLongitude(value);
        fin.ignore();

        fin.close();
    }
    cout << mc3 << endl;

}
void outFile(string f){
    ofstream fout;
    string line = "";
    fout.open(f);
    if(fout.fail()){
        cout << "mc" << " did not open\n";
        exit(1);
    }
    if(fout.is_open()){
        fout << mc1 << endl;
        fout << mc2 << endl;
        fout.close();
    }
}
