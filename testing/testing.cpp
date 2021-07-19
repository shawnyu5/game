//purpose of this file: 
//Date: 2021-07-17
//---------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include "../hangman.h"
using std::cout;
using std::endl;
using std::string;
using namespace sdds;

int main ()
{
    HangMan test1;
    test1.getWordFromFile();
    test1.setAttempt();
    test1.setHints();
    test1.attempt();
    //test1.display(cout);
}


