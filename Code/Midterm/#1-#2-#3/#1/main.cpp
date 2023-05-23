//
//  main.cpp
//  #1
//
//  Created by Nico Savage on 5/22/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

double arr[] = {4.5,6.7,2.3,9.7,1.3,4.9,2,11.5,13.9,10.2,19.6,3.5,1.1,0.9,12.3};
int sizeOfArray = sizeof(arr) / sizeof(arr[0]);

double numAvg(double num[], int size);
void differnce(double num[],int size);
int main(int argc, const char * argv[]) {
    double ave = numAvg(arr, sizeOfArray);
    differnce(arr, sizeOfArray);
    
}

double numAvg(double num[], int size){
    double sum = 0;
    for(int i = 0;i < size;i++){
        sum += num[i];
    }
    return sum / size;
}
void differnce(double num[],int size){
    double average = numAvg(arr, sizeOfArray);
    cout << fixed << setprecision(2);
    cout <<setw(7) << left <<"Avg " << setw(15)<< right <<"Difference from Average" << endl;
    for(int i = 0;i < size;i++){
        double diff = average - num[i];
        if(abs(diff) > 5.0){
            cout << setw(7) << left << num[i] << setw(15) << right << "Big difference " << endl;
            
        }else{
            cout << setw(7) << left << num[i] << setw(15) << right << diff << endl;
        }
    }
    cout << "__________________________\n";
        cout <<"Avg " << average << endl;
    }

