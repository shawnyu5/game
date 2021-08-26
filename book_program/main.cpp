//purpose of this file: run book program
//Date: 2021-08-25
//---------------------------------
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
#include "book.h"
using std::cout;
using std::endl;
using std::string;

int main ()
{
    Book book;

    //adds some books to store
    book.addBook("war and peace", "leo tolstoy", "amazon", 21.0, 100);
    book.addBook("song of solomon", "toni morrison", "target", 16.00, 50);
    book.addBook("ulysse", "james joyce", "joyce and co", 17, 100);
    book.addBook("the shadow of the wind", "carlos ruiz zafon", "amazon", 34, 10);
    //book.addBook("<++>", "<++>", "<++>", <++>, <++>);
    //book.addBook("<++>", "<++>", "<++>", <++>, <++>);
    //book.addBook("<++>", "<++>", "<++>", <++>, <++>);

    //testing search function
    cout << book.search("war and peace", "leo tolstoy") << '\n'; //100
    cout << book.search("war and peace", "toni tolstoy") << '\n'; //-1
    cout << book.search("the shadow of the wind", "carlos ruiz zafon") << '\n'; //10
}


