//
//  main.cpp
//  graphLecture
//
//  Created by Nico Savage on 6/14/23.
/*
 Prove it works by building and detecting two additional cycles
 UNV -> AVP -> PHL -> UNV
 MDT -> LBE -> PHL -> AVP -> MDT
 */

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
    for(int row = 0; row < NODES; row++){
        for(int col = row + 1; col < NODES; col++){
            int weight = rand() % 10 + 1;
            matrix[row][col] = weight;
            matrix[col][row] = weight;
        }
    }
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
//    if(!directed){
//        matrix[col][row] = 1;
//    }
    
}

void showAllConnectionsFromNode(int matrix[NODES][NODES], int node){
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

bool hasCycle(int matrix[NODES][NODES], int startNode, int currentNode, bool visited[]){
    visited[currentNode] = true;

    for(int col = 0; col < NODES; col++){
        if(matrix[currentNode][col] == 1){
            if(!visited[col]){
                if(hasCycle(matrix, startNode, col, visited))
                    return true;
            }
            else if(col == startNode)
                return true;
        }
    }

    visited[currentNode] = false;
    return false;
}

void shortestPaths(int matrix[NODES][NODES], int startNode){
    int INF = INT_MAX;
    int distance[NODES];
    bool visited[NODES] = {false};
    for(int i = 0; i < NODES; i++){
        distance[i] = INF;
    }
    distance[startNode] = 0;
    for(int i = 0; i < NODES - 1; i++){
        int minDistance = INF;
        int minNode = -1;
        for(int j = 0; j < NODES; j++){
            if(!visited[j] && distance[j] < minDistance){
                minDistance = distance[j];
                minNode = j;
            }
        }
        if(minNode == -1){
            break;
        }

        visited[minNode] = true;
        for(int j = 0; j < NODES; j++){
            if(matrix[minNode][j] != 0 && !visited[j]){
                int newDistance = distance[minNode] + matrix[minNode][j];
                if(newDistance < distance[j]){
                    distance[j] = newDistance;
                }
            }
        }
    }
    cout << "Shortest paths from " << nodeNames[startNode] << ":" << endl;
    for(int i = 0; i < NODES; i++){
        if(i != startNode){
            cout << nodeNames[i] << ": ";
            cout << distance[i] << endl;
        }
    }
}


int main(int argc, const char * argv[]) {
    int matrix[NODES][NODES];
    initializeArray(matrix);
//    setKnownConnection(matrix, 0, 4);
//    setKnownConnection(matrix, 4, 3);
//    setKnownConnection(matrix, 3, 0);
//    setKnownConnection(matrix, 5, 6);
//    setKnownConnection(matrix, 0, 4);
    
//    setKnownConnection(matrix, 5, 6);
//    setKnownConnection(matrix, 6, 3);
//    setKnownConnection(matrix, 3, 5);
//
//    setKnownConnection(matrix, 1, 2);
//    setKnownConnection(matrix, 2, 3);
//    setKnownConnection(matrix, 3, 6);
//    setKnownConnection(matrix, 6, 1);
//    displayMatrix(matrix);
//
//    if (hasCycle(matrix, 1, 1, new bool[NODES]{}))
//        cout << "Cycle detected!" << endl;
//    else
//        cout << "No cycle detected." << endl;
    
    initializeRandomArray(matrix);
    displayMatrix(matrix);

    int startNode = 0;  // Example: Start from ERI
    shortestPaths(matrix, startNode);

    return 0;
}



