//
//  main.cpp
//  graphLecture
//
//  Created by Nico Savage on 6/14/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <queue>
#include <set>
#define NODES 7
using namespace std;

string nodeNames[NODES] = {"ERI", "MDI", "LBE", "PHL", "PIT", "UNV", "AVP"};

void initializeArray(int matrix[NODES][NODES]){
    for(int row = 0; row < NODES;row ++){
        for(int col = 0; col < NODES; col++){
            matrix[row][col] = 0;
        }// end col
    }// end row
}

void initializeRandomArray(int matrix[NODES][NODES]){
    for(int row = 0; row < NODES;row ++){
        for(int col = 0; col < NODES; col++){
            if(row == col){
                matrix[row][col] = 0;
                //no self links
            }else{
                matrix[row][col] = int(rand() % 2);
                matrix[col][row] = matrix[row][col];
            
            }
            
        }// end col
    }// end row
}

void displayMatrix(int matrix[NODES][NODES]){
    cout << "    ";
    for(int row = 0; row < NODES; row++){
        cout << setw(5) << nodeNames[row];
    }
    cout << endl;
    for(int row = 0; row < NODES; row++){
        cout << nodeNames[row];
        for(int col = 0; col < NODES; col++){
            cout << setw(5) << matrix[row][col];
        }// end col
        cout << endl;
    }// end row
}

void setKnownConnection(int matrix[NODES][NODES], int row, int col, bool directed = false){
        matrix[row][col] = 1;
    if(!directed){
        matrix[col][row] = 1;
    }
    
}

void showAllConnectionsFromNode(int matrix[NODES][NODES], int node){
//    cout << "Connections from " << nodeNames[node] << endl;
//    for(int col = 0; col < NODES; col++){
//        if(matrix[node][col] == 1){
//            cout << nodeNames[col] << endl;
//        }
//    }
    int startNode = node;
    queue<int> links;
    set<string> connections;
    set<string>::iterator conItr;
    bool visited[NODES] = {false, false, false, false, false, false, false};
    
    links.push(node); // put the starting location inside the queue
    visited[node] = true;
    
    while(!links.empty()){
        node = links.front();
        links.pop();
        for(int col = 0; col < NODES; col++){
            if(matrix[node][col] == 1 && visited[col] == false){
                //cout << nodeNames[col] << endl;

                links.push(col);
                visited[col] = true;
                connections.insert(nodeNames[col]);
            }//end if
        }// end for
    }// end while
        cout << nodeNames[startNode] << " connects to ";
    for (conItr = connections.begin(); conItr != connections.end(); conItr++){
        cout << *conItr << " ";
    }
    cout << endl;


}

int main(int argc, const char * argv[]) {
    int matrix[NODES][NODES];
    initializeArray(matrix);
//    setKnownConnection(matrix, 0, 1);
//    setKnownConnection(matrix, 2, 3);
//    setKnownConnection(matrix, 3, 4, true);
//    initializeRandomArray(matrix);
    
    setKnownConnection(matrix, 1, 2);
    setKnownConnection(matrix, 4, 3);
    setKnownConnection(matrix, 4, 1);
    setKnownConnection(matrix, 5, 6);
    setKnownConnection(matrix, 0, 1);

    displayMatrix(matrix);
    showAllConnectionsFromNode(matrix, 1);

}
