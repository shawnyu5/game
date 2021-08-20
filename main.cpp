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
    cout << "=================================\n"
        << "     Welcome To Hang Man        \n"
        << "=================================\n\n"
        << "1. Play Game" << endl
        << "2. Set New Word" << endl << endl
        << "Your Choice: ";

    string choice{};
    std::getline(std::cin, choice);

    //HangMan game1;
    if(choice == "1")
    {
        HangMan game{};
        game.run(game);
#if 0
        //retrieve the correct word
        game1.getWordFromFile();

        //how many attemps are allowed by the user
        game1.setAttempt();
        game1.setHints();
        game1.display(cout);

        //keep asking for attemps until attemp returns true
        while(!game1.attempt());

        //game1.display(cout);
#endif
    }
    else if (choice == "2")
    {
        HangMan game;
        game.setWord();
    }
    else
    {
        cout << "Invalid input" << endl;
    }
}


