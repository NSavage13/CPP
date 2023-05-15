#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int readFile(string f);
int threeAve();
vector<int> temps;
vector<int> threeWeekAve;
vector<string> line;
vector<int> sqError;
int month[7][5];

int values();
int main(){
    
    int records;
    records = readFile("demotemps.txt");
    
    cout << setw(10) << "Day" << setw(10) <<  "Value" << setw(20) << "3 week average"  << setw(10) << "Error" << setw(20)<< "Squared error"<<endl;
//    for(int i=0;i<8;i++){
//        cout << setw(10) << i+1 << setw(10) << temps[i]<< endl;
//    }
    int ave = threeAve();
    cout << ave;
    
    
}

int threeAve(){
    int i=0;
    int j=0;
    int k=0;
    int sum=0;
    int average=0;
    int error=0;
    int squaredError=0;
    
    int total=0;
    for (int i = 0; i < 3; i++) {
        threeWeekAve.push_back(0);
        sqError.push_back(0);
    }
    for(i=0;i<8;i++){
        sum=0;
        for(j=i;j<i+3;j++){
            sum+=temps[j];
        }
        average=sum/3;
        threeWeekAve.push_back(average);
    }
    for(k=0;k<8;k++){
        error = temps[k]-threeWeekAve[k];
        squaredError=pow(error,2);
        sqError[k] = squaredError;
        total += sqError[k];
        if (k<3){
            sqError[k] = 0;
            error = 0;
        }
        for (int i=0;i<3; i++) {
            threeWeekAve.push_back(0);
            
        }
        
        if(k==7){
            error = 0;
            sqError[k] = (sqError[3] + sqError[4] + sqError[5] + sqError[6]) / 4;
            cout << setw(10) << k+1 << setw(10) << temps[k]<< setw(20) << threeWeekAve[k]  << setw(10) << error << setw(20)<< sqError[k]<<endl;
        }else{
            
            cout << setw(10) << k+1 << setw(10) << temps[k]<< setw(20) << threeWeekAve[k]  << setw(10) << error << setw(20)<< sqError[k]<<endl;
        }
    }
    return 0;
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

        }
        temps.push_back(temp);

    }
    temps[7] = 0;

    fin.close(); // close file
    return records;
}
