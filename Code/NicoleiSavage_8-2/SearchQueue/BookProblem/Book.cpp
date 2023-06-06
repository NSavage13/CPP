//
//  Book.cpp
//  BookProblem
//
//  Created by Nico Savage on 6/6/23.
//

#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

class Book {
public:
    int rank, year;
    string author, book;
    
    friend ostream& operator <<(ostream& os,const Book& book){
        os << "Rank: "<< book.rank << endl;
        os << "Author: "<< book.author << endl;
        os << "Book Title: "<< book.book << endl;
        os << "Year: "<< book.year << endl;
        return os;
    }
    bool operator =(Book& b){rank = b.rank;author = b.author;book = b.book;year = b.year;return true;}
    bool operator ==(const Book& book)const{return rank == book.rank;}
    bool operator <(const Book& book)const{return rank < book.rank;}
    bool operator >(const Book& book)const{return rank > book.rank;}
};
