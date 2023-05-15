//
//  main.cpp
//  example
//
//  Created by Nico Savage on 5/12/23.
//

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;
vector<int> temps;
//---------------------------------------------------------------------

int readFile(string filename); // read files
double naiveForecastTable(); // build table, calc, and return error
double absError(double actual, double forecast); // calculatest the absoluta error
double avgPastValue();
double avgPastValue(int history);
int getHistory();
int getValidInt();

//---------------------------------------------------------------------

int main(){
    int records;
    double naiveError;
    double avgPastError = 0;
    double avgPastHistoryError = 0;

    records = readFile("demot.txt");
    if(records <= 0){
        cout << "file not read, quitting\n";
        return -1;
    }
    cout << records << " temperatures read\n";
    naiveError = naiveForecastTable();
    avgPastError = avgPastValue();
    avgPastHistoryError = avgPastValue(getHistory());

    cout << "Naive Error = " << naiveError << endl;
    cout << "Avg Past Error = " << avgPastError << endl;
    cout << "Avg Past Error (history) = " << avgPastHistoryError << endl;
}

//--------------------------
double avgPastValue(){
    double forecast;
    double actual;
    double error = 0;
    double totError = 0;
    double totTemps = 0;
    double meanAbsErr = 0; // mean absoluet error


    cout << setw(10) << "day" << setw(10) <<  "forecast" << setw(10) << "actual"  << setw(10) << "Error" <<endl;

    ///this is a bad bad no no dont nest for loops if you dont have to
    /*
    for ( int curDay = 1 ; curDay < temps.size(); curDay ++ ){

        for(back = curDay-1; back>=0; back--){
            totTemps += temps.at(back);
        }
        forecast = totTemps / curDay;
        actual = temps.at(curDay);
        error = absError(actual, forecast);
        totError += error;
        totTemps = 0;
        cout << setw(10) << curDay << setw(10) <<  forecast << setw(10) << actual  << setw(10) << error <<endl;
    }
    */
    for ( int curDay = 1 ; curDay < temps.size(); curDay ++ ){
        totTemps += temps.at(curDay-1);
        forecast = totTemps / curDay;
        actual = temps.at(curDay);
        error = absError(actual, forecast);
        totError += error;
        cout << setw(10) << curDay << setw(10) <<  forecast << setw(10) << actual  << setw(10) << error <<endl;

//        cout << endl;
    }
    meanAbsErr = totError / (temps.size()-1);
    return meanAbsErr;
}
double avgPastValue(int history){
    double forecast;
    double actual;
    double error = 0;
    double totError = 0;
    double totTemps = 0;
    double meanAbsErr = 0; // mean absoluet error

    int back;
    cout << setw(10) << "day" << setw(10) <<  "forecast" << setw(10) << "actual"  << setw(10) << "Error" <<endl;

    for ( int curDay = 1 ; curDay < temps.size(); curDay ++ ){
        totError = 0;
        for(back = curDay-1;  (curDay-history<0)?back>=0:back>=curDay-history ; back--){
            totTemps += temps.at(back);
        }
        forecast = totTemps / history;
        actual = temps.at(curDay);
        error = absError(actual, forecast);
        totError += error;
        totTemps = 0;
        cout << setw(10) << curDay << setw(10) <<  forecast << setw(10) << actual  << setw(10) << error <<endl;
    }
    meanAbsErr = totError / (temps.size()-1);
    return meanAbsErr;
}

double naiveForecastTable(){
    double forecast;
    double actual;
    double error = 0;
    double totError = 0 ;
    double meanAbsErr = 0 ; // mean absoluet error
    cout << setw(10) << "day" << setw(10) <<  "forecast" << setw(10) << "actual"  << setw(10) << "Error" <<endl;
    // logic vv
    for ( int curDay = 1 ; curDay < temps.size(); curDay ++ ){
        forecast = temps.at(curDay-1);
        actual = temps.at(curDay);
        error = absError(actual, forecast);
        totError += error;
        cout << setw(10) << curDay << setw(10) <<  forecast << setw(10) << actual  << setw(10) << error <<endl;
    }

    meanAbsErr = totError / (temps.size() - 1);
    return meanAbsErr;
}

double absError(double actual, double forecast){
    return abs(actual-forecast);
}

int readFile(string filename){
    ifstream fin;
    int records = 0;//changed
    int temp;
    string input;
    fin.open(filename);
    if(fin.fail()){
        cout << filename << " did not open, quitting\n";
        return 0;
    }
    while(getline(fin, input)){
        records ++;
        try{
            temp = stoi(input);
        }
        catch(exception ex){
            //ignore a bad read!
        }
        //cout << temp << " ";
        temps.push_back(temp);

    }

    fin.close(); // close file
    return records;
}

int getHistory(){
    cout << "What is the history Refresh (days of memory) : ";
    return getValidInt();
}

int getValidInt(){
    int input;
    cin >> input;
    while(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, try again: ";
        cin >> input;
    }
    return input;
}



