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
    Book bookStore;

    //adds some books to store
    cout << "============adding books===========" << '\n';
    bookStore.addBook("war and peace", "leo tolstoy", "amazon", 21.0, 100);
    bookStore.addBook("song of solomon", "toni morrison", "target", 16.00, 50);
    bookStore.addBook("ulysse", "james joyce", "joyce and co", 17, 100);
    bookStore.addBook("the shadow of the wind", "carlos ruiz zafon", "amazon", 34, 10);

    cout << '\n';
    cout << "==================Initial stock=============== " << "\n\n";
    bookStore.display();
    //bookStore.addBook("<++>", "<++>", "<++>", <++>, <++>);
    //bookStore.addBook("<++>", "<++>", "<++>", <++>, <++>);
    //bookStore.addBook("<++>", "<++>", "<++>", <++>, <++>);

    //testing search function
    cout << "==========Testing Search Function=================" << '\n';
    cout << "war and peace by leo tolstoy: " << bookStore.search("war and peace", "leo tolstoy") << '\n'; //100
    cout << "war and peace by toni tolstoy: " << bookStore.search("war and peace", "toni tolstoy") << '\n'; //-1
    cout << "the shadow of the wind by carlos ruiz zafon: " << bookStore.search("the shadow of the wind", "carlos ruiz zafon") << '\n'; //10

    cout << '\n' << "=============adding inventory==========" << '\n';
    //adding inventory
    bookStore.addInventory("war and peace", "leo tolstoy", 100);
    bookStore.addInventory("song of solomon","toni morrison", 2);
    bookStore.addInventory("the shadow of the wind","carlos ruiz zafon", 1000);
    bookStore.addInventory("war and peace", "toni tolstoy", 20); //does not exist

    cout << '\n';

    cout << "war and peace by leo tolstoy: " << bookStore.search("war and peace", "leo tolstoy") << '\n'; //100
    cout << "song of solomon by toni morrison: " << bookStore.search("song of solomon", "toni morrison") << '\n'; //0
    cout << "the shadow of the wind by carlos ruiz zafon: " << bookStore.search("the shadow of the wind", "carlos ruiz zafon") << '\n'; //10

    cout << '\n' << "=================After inventory adjustment=============== " << '\n';
    bookStore.display();
}


