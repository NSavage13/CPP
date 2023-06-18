//
//  main.cpp
//  Part1
//
//  Created by Nico Savage on 6/14/23.
//
#include "binarySearchTree.h"
#include "IndexCode.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
/*Overload search to accept a string. Basically yoûare modifying how search uses the IndexNode we built in class.
 
 return the position (index) of the item found.
 Return -1 if not found
 In a main, use search to find several items in the array
 */
int fillWords(string filename, vector<string> &words,
    bSearchTreeType<IndexNode> &index)
{
    ifstream fin(filename);
    string line;
    int count = 0;
    if(fin.fail()){
        cout << filename << " did not open " << endl;
        exit(-1);}//end if
    while(getline(fin, line)){
        words.push_back(line);
        index.insert(IndexNode(line, count));
        count ++;}//end while
    fin.close();
    return count;
}
int main()
{
        vector<string> wordList;
        bSearchTreeType<IndexNode> index;

        int count = fillWords("adjective.txt", wordList, index);
        wordList.push_back("helpful");
        
        string searchTerm = "helpful";
        int position = index.search("terrific");
        
        count ++;
        if (position != -1) {
            cout << "Found at position: " << position << endl;
        } else {
            cout << "Not found." << endl;
        }
    
//    vector<string> wordList;
//    bSearchTreeType<IndexNode> index;
//    int count = fillWords("adjective.txt", wordList, index);
//
//

//
//
//    if(index.search(IndexNode("helpful", 0))){
//        cout << "found" << endl;
//    }
//    else {
//        cout << "NOT found" << endl;
//    }
    

    //index.inorderTraversal();

    /*
    bSearchTreeType<int>  tree1;
    bSearchTreeType<int>  tree2;
    bSearchTreeType<int>  tree3;

    int num;

    cout << "Enter numbers ending with -999" << endl;
    cin >> num;

    while (num != -999)
    {
        tree1.insert(num);
        cin >> num;
    }

    cout << endl << "tree1 nodes in postorder: ";
    tree1.insertPostorder(tree2);
    cout << endl;

    cout << endl << "tree2 nodes in preorder: ";
    tree2.insertPreorder(tree3);
    cout << endl;

    cout << endl << "tree3 nodes in inorder: ";
    tree3.inorderTraversal();
    cout << endl;


    cout << "tree1 height: " << tree1.treeHeight() << endl;
    cout << "tree1 leaves: " << tree1.treeLeavesCount() << endl;
    cout << "tree2 height: " << tree2.treeHeight() << endl;
    cout << "tree2 leaves: " << tree2.treeLeavesCount() << endl;
    cout << "tree3 height: " << tree3.treeHeight() << endl;
    cout << "tree3 leaves: " << tree3.treeLeavesCount() << endl;
    cout << endl;

`*/
    return 0;
    
}
