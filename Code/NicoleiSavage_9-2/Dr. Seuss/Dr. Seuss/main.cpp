//
//  main.cpp
//  Dr. Seuss
//
//  Created by Nico Savage on 6/14/23.
/*
 Attached is a copy of Dr. Seuss’ Green Eggs and Ham. Your program will read the entire book. It will then create an index of the page numbers for each word. For simplicity, you can treat the blank lines as new pages. If needed, edit the file to insert page numbers in the blank lines.
 
 Create an IndexNode that holds a vector of integers and a keyword. The vector will list every page that the word is listed on.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class IndexNode {
public:
    string keyword;
    vector<int> pageNumbers;

    IndexNode(const string& key) : keyword(key) {}
};

int main() {
    ifstream fin("textfile.txt");
    if (!fin) {
        cout << "Failed to open the text file." << endl;
        return 1;
    }

    vector<IndexNode> index;

    string line;
    int pageNumber = 1;

    while (getline(fin, line)) {
        if (line.empty()) {
            pageNumber++;
            continue;
        }

        string word;
        istringstream iss(line);

        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); }), word.end());

            bool found = false;
            for (IndexNode& node : index) {
                if (node.keyword == word) {
                    if (find(node.pageNumbers.begin(), node.pageNumbers.end(), pageNumber) == node.pageNumbers.end()) {
                        node.pageNumbers.push_back(pageNumber);
                    }
                    found = true;
                    break;
                }
            }

            if (!found) {
                IndexNode newNode(word);
                newNode.pageNumbers.push_back(pageNumber);
                index.push_back(newNode);
            }
        }
    }

    fin.close();

    // Print the index
    for (const IndexNode& node : index) {
        cout << node.keyword << ": ";
        for (const int& pageNum : node.pageNumbers) {
            cout << pageNum << " ";
        }
        cout << endl;
    }

    return 0;
}

