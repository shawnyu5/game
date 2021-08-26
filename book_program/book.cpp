//purpose of this file:
//Date: 2021-08-25
//---------------------------------
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
#include <algorithm>
#include "book.h"
using std::cout;
using std::endl;
using std::string;

//custom constuctor
Book::Book(string author, string publisher, string title, double price, int copies)
{
    m_author = author;
    m_publisher = publisher;
    m_title = title;
    m_price = price;
    m_copies = copies;
}

//adds a book to vector
void Book::addBook(string title, string author, string publisher, double price, int copies)
{
    m_books.push_back(Book{author, publisher, title, price, copies});
    cout << title << " by " << author << " added" << '\n';
}

//searches by book title and author, return the number of copies aviliable
int Book::search(string title, string author){
    //auto find_algo = [&](Book& obj)
    //{
        //return obj.m_title == title && obj.m_author == author;
    //};
    //std::find_if(m_books.begin(), m_books.end(), find_algo);

    for (auto& current : m_books)
    {
        if(current.m_title == title && current.m_author == author)
        {
            return current.m_copies;
        }
    }

    //return invalid value if nothing is found
    return -1;
}

//subtracts the number of books passed in
void Book::buy(string title, string author, int bought)
{
    //make sure the book exist
    if (search(title, author) > -1)
    {
        for (auto& current : m_books)
        {
            if(current.m_title == title && current.m_author == author)
            {
                current.m_copies -= bought;
                cout << title << " inventory bought" << '\n';
            }
        }
    }
    else
    {
        cout << "book " << title << " by " << author << " does not exist" << '\n';
    }
}

//add inventory for a title
void Book::addInventory(string title, string author, int bought)
{
    //make sure the book exist
    if (search(title, author) > -1)
    {
        for (auto& current : m_books)
        {
            if(current.m_title == title && current.m_author == author)
            {
                current.m_copies += bought;
                cout << title << " inventory added" << '\n';
            }
        }
    }
    else
    {
        cout << "book " << title << " by " << author << " does not exist" << '\n';
    }
}

//display
void Book::display()
{
    for (auto& current : m_books)
    {
        cout << "Title: " << current.m_title << '\n'
            << "Author: " << current.m_author << '\n'
            << "Publisher: " << current.m_publisher << '\n'
            << "Price: $" << current.m_price << '\n'
            << "Copies: " << current.m_copies << "\n\n";
    }
}


