//
//  main.cpp
//  BookProblem
//
//  Created by Nico Savage on 5/25/23.
/*
 Build a STL queue using the class that you developed for the book list from CPP 7-1. Create a linear search algorithm that searches the queue for a book title, and then displays the data in the node.
 */
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include "Book.cpp"
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

queue<Book> bookQueue;
set<Book> bookSet;
Book book;
string bookTitle;
bool gotIt = false;

void getFile(string fileName);
void getBook();

int main(int argc,  char * argv[]) {
    getFile("booklist.txt");
    getBook();
    return 0;
}


void getBook() {
    cout << "Enter a book title to search: ";
    getline(cin, bookTitle);
    transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);

    while (!bookQueue.empty()) {
        Book frontB = bookQueue.front();
        bookQueue.pop();

        string lowercaseTitle = frontB.book;
        transform(lowercaseTitle.begin(), lowercaseTitle.end(), lowercaseTitle.begin(), ::tolower);

        if (lowercaseTitle.find(bookTitle) != string::npos) {
            bookSet.insert(frontB);
            gotIt = true;
        }
    }
    for(set<Book>::iterator it = bookSet.begin(); it != bookSet.end(); ++it){
            cout << *it << endl;
    }
    if (!gotIt) {
        cout << "Book not found\n";
    }
}



void getFile(string fileName){
    ifstream fin("booklist.txt");
    string line = "";
    if(fin.fail()){
        cout << "booklist.txt did not open\n";
        exit(1);
    }
    while(getline(fin,line)){
        book.rank = stoi(line);
        getline(fin,book.author);
        getline(fin,book.book);
        getline(fin,line);
        book.year = stoi(line);
        bookQueue.push(book);
    }
    fin.close();
}
