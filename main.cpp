//purpose of this file: runs C++ game
//Date: 2021-07-17
//---------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include "hangMan_program/hangMan.h"
#include "quiz_program/quiz.h"
using std::cout;
using std::endl;
using std::string;
using namespace sdds;

int main ()
{
    cout << "=================================\n"
        << "              Welcome \n"
        << "=================================\n\n"
        << "1. Hang Man" << endl
        << "2. C++ quiz" << "\n\n";

    int choice{};
    bool valid{false};
    while(!valid)
    {
        cout << "Your Choice: ";
        //ensure user input is a number
        try
        {
            string temp;
            std::getline(std::cin, temp);
            choice = stoi(temp);
            valid = true;
        }
        catch(...)
        {
            cout << "invalid entry" << '\n';
        }
    }

    switch (choice)
    {
        case 1:
            HangMan::run();
            break;
        case 2:

            Quiz quiz;

            quiz.addQuestion(Question{"Which of the following is an example of a fundamental data type?",
                    "function",
                    "char",
                    "array",
                    "class",
                    2
                    });

            quiz.addQuestion(Question{"Which type of conversion is known as 'Automatic Conversion'?",
                    "Explicit Conversion",
                    "Auto Conversion",
                    "Implicit Conversion",
                    "Simple Conversion",
                    3});

            quiz.addQuestion(Question{"Symbols that perform operations on variables are called...?",
                    "Operators",
                    "Data Types",
                    "Variables",
                    "Modifiers",
                    1});

            quiz.addQuestion(Question{"Which of the following is NOT an example of an operator?",
                    "Logical Operators",
                    "Arithmetic Operators",
                    "Relational Operators",
                    "Symbol Operators",
                    4});

            quiz.addQuestion(Question{"Which symbol expresses 'not equal'?",
                    ">=",
                    "!=",
                    "<=",
                    "==",
                    2});

            quiz.addQuestion(Question{"Which is the correct format for single line comment?",
                    "/*this is a comment",
                    "##this is a comment",
                    "//this is a comment",
                    "**this is a comment",
                    3});

            quiz.addQuestion(Question{"Which of the following expresses a logical 'OR'?",
                    "||",
                    "&&",
                    "!",
                    "OR",
                    1});

            quiz.addQuestion(Question{"Which of the following is the symbol for remainder after division?",
                    "-",
                    "=",
                    "^",
                    "%",
                    4});


            quiz.addQuestion(Question{"The increment operator, '++', increases the value of the operand by...?",
                    "7",
                    "2",
                    "1",
                    "0",
                    3});

            quiz.addQuestion(Question{"Which is the correct format for the cout statement?",
                    "'cout' << \"hello world\"",
                    "cout << \"hello world\"",
                    "cout >> \"hello world\"",
                    "<cout> \"hello world\"",
                    2});

            quiz.addQuestion(Question{"What is the difference between a class and struct in C++?",
                    "they named different",
                    "Classes allow private members, while structs does not",
                    "Structs allow private members, while classes does not",
                    "there is no difference",
                    2});

            quiz.addQuestion(Question{"What is a vector?",
                    "A math equation",
                    "An array that requires the user to manage memory",
                    "an array that automatically grows and shrinks as it needs",
                    "None of the above",
                    3});

            quiz.run(quiz);
    }
}
