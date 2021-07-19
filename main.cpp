//purpose of this file: run hangMan game
//Date: 2021-07-17
//---------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include "hangMan.h"
using std::cout;
using std::endl;
using std::string;
using namespace sdds;

int main ()
{
    HangMan game1;
    //retrieve the correct word
    game1.getWordFromFile();

    //how many attemps are allowed by the user
    game1.setAttempt();
    game1.setHints();
    game1.display(cout);

    //keep asking for attemps until attemp returns true
    while(!game1.attempt());
    //game1.display(cout);
}


