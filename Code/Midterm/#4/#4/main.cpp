//
//  main.cpp
//  #4
//
//  Created by Nico Savage on 5/22/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <map>
using namespace std;


int main(int argc, const char * argv[]) {
    ifstream fin;
    string line = "";
    map<int, int> numberFrequencies;

    fin.open("numbers.txt");
    if (fin.fail()) {
            cout << "numbers.txt did not open\n";
            exit(1);
        }

    while (getline(fin, line)) {
        try {
            int number = std::stoi(line);
            numberFrequencies[number]++;
        } catch (invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << endl;
        }
    }

        
    cout << "Number Frequencies:\n";
    for (auto& pair : numberFrequencies) {
            std::cout << pair.first << " - " << pair.second << " occurrences\n";
        }

        fin.close();
    
//    int counter = 0;
//    ifstream fin;
//    string line = "";
//    fin.open("numbers.txt");
//    if(fin.fail()){
//        cout << "numbers.txt did not open\n";
//        exit(1);
//    }
//    while(getline(fin, line)){
//
//        if (line == "42"){
//            counter ++;
//        }
//    }
//    cout << "The number 42 appears " << counter << " times in the file.\n";
    

}
