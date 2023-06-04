//
//  main.cpp
//  BookProblem
//
//  Created by Nico Savage on 5/25/23.
/*
 I have included a file called booklist.txt. This file contains information on 100 famous Science Fiction books. Each line holds another part of the record. The record structure is
 rank
 author
 book
 year published
 Create a class that holds this information. Be sure to overload <<, =, ==, < and >. For < and >, compare the rank.
 Read the file and fill a list with the 100 books. Display the list to the screen. Bonus if you use the output_iterative.
 */
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

class Book {
public:
    int rank, year;
    string author, book;
    
    friend ostream& operator <<(ostream& os,const Book& book){
        os << book.rank << endl;
        os << book.author << endl;
        os << book.book << endl;
        os << book.year << endl;
        return os;
    }
    bool operator =(Book& b){rank = b.rank;author = b.author;book = b.book;year = b.year;return true;}
    bool operator ==(const Book& book)const{return rank == book.rank;}
    bool operator <(const Book& book)const{return rank < book.rank;}
    bool operator >(const Book& book)const{return rank > book.rank;}
};

int main(int argc,  char * argv[]) {
    list<Book> bookList;
    Book book;
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
        bookList.push_back(book);
    }
    fin.close();
    ostream_iterator<Book> outIterator(cout, "\n");
    //bookList.sort(greater<Book>());
    bookList.sort();
    copy(bookList.begin(), bookList.end(), outIterator);
}
