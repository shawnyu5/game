//purpose of this file:
//Date: 2021-08-25
//---------------------------------
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::string;

class Book
{
private:
    string m_title{};
    string m_author;
    string m_publisher{};
    double m_price{0};
    int m_copies{0};

    //vector of books
    std::vector<Book> m_books;

public:
    //default constuctor
    Book()
    {}

    //custom constuctor
    Book(string author, string publisher, string title, double price, int copies);

    //adds a book to vector
    void addBook(string title, string author, string publisher, double price, int copies);

    //searches by book title and author, return the number of copies aviliable
    int search(string title, string author);

    //subtracts the number of books passed in
    void buy(string title, string author, int bought);

    //add inventory for a title ONLY IF THE TITLE EXIST
    void addInventory(string title, string author, int bought);

    //display
    void display();
};
#endif
