#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    
    string lastnameA, firstnameA;
    double currentSalaryA,percentPayIncreaseA, updatedSalaryA;

    string lastnameB, firstnameB;
    double currentSalaryB,percentPayIncreaseB, updatedSalaryB;

    string lastnameC, firstnameC;
    double currentSalaryC,percentPayIncreaseC, updatedSalaryC;

    ifstream inFile;
    ofstream outFile;
    inFile.open("/Users/nicosavage/Desktop/C++/NicoleiSavage_1-2/ch3-ex5/ch3-ex5/ch3ex5.txt");
    outFile.open("/Users/nicosavage/Desktop/C++/NicoleiSavage_1-2/ch3-ex5/ch3-ex5/ch3ex5output.dat");
    outFile << setprecision(2) << showpoint << fixed;

    inFile >> lastnameA >> firstnameA >> currentSalaryA >>
            percentPayIncreaseA;

    inFile >> lastnameB >> firstnameB >> currentSalaryB >>
            percentPayIncreaseB;

    inFile >> lastnameC >> firstnameC >> currentSalaryC >>
            percentPayIncreaseC;

    updatedSalaryA = currentSalaryA + (currentSalaryA * percentPayIncreaseA / 100);
    updatedSalaryB = currentSalaryB + (currentSalaryB * percentPayIncreaseB / 100);
    updatedSalaryC = currentSalaryC + (currentSalaryC * percentPayIncreaseC / 100);

    outFile << lastnameA << " " << firstnameA << " " << updatedSalaryA <<endl;
    outFile << lastnameB << " " << firstnameB << " " << updatedSalaryB <<endl;
    outFile << lastnameC << " " << firstnameC << " " << updatedSalaryC <<endl;

    inFile.close();
    outFile.close();
    return 0;
}
