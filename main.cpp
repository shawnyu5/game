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

    system("clear");
    switch (choice)
    {
        case 1:
            HangMan::run();
            break;
        case 2:

            Quiz quiz;

            quiz.addQuestion(Question{"Which data type is used to create a variable that should store text?",
                    std::vector<string>
                    {
                    "string",
                    "Txt",
                    "String",
                    "myString",
                    },
                    1});

            quiz.addQuestion(Question{"How do you create a variable with the numeric value 5?",
                    std::vector<string> {
                    "double x = 5;",
                    "int x = 5;",
                    "x = 5;",
                    "num x = 5;",
                    "string x = 5;"
                    },
                    2});

            quiz.addQuestion(Question{"Array indexes start at index:",
                    std::vector<string>
                    {
                    "0",
                    "1",
                    },
                    1});

            quiz.addQuestion(Question
                    {"Which method can be used to find the length of a string?",
                    std::vector<string>
                    {
                    "len()",
                    "length()",
                    "getSize()",
                    "getLength()"
                    },
                    2});

            quiz.addQuestion(Question{"Which header file lets us work with input and output objects?",
                    std::vector<string>
                    {
                    "#include <stream>",
                    "#include <iosstream>",
                    "#include <inputstream>",
                    "#include <iostream>"
                    },
                    4});

            quiz.addQuestion(Question{"Which operator can be used to compare two values?",
                    std::vector<string>
                    {
                    "<>",
                    "=",
                    "==",
                    "><"
                    },
                    3});

            quiz.addQuestion(Question{"Which is the correct format for the cout statement?",
                    std::vector<string>
                    {
                    "'cout' << \"hello world\";",
                    "cout << \"hello world\";",
                    "cout >> \"hello world\";",
                    "<cout> \"hello world\";"
                    },
                    2});

            quiz.addQuestion(Question{"What is the difference between a class and struct in C++?",
                    std::vector<string>
                    {
                    "they named different",
                    "Classes allow private members, while structs does not",
                    "Structs allow private members, while classes does not",
                    "there is no difference"
                    },
                    2});

            quiz.addQuestion(Question{"What is a vector?",
                    std::vector<string>
                    {
                    "An array that requires the user to manage memory",
                    "an array that automatically grows and shrinks as it needs",
                    "None of the above"
                    },
                    2});

            quiz.run(quiz);
    }
}
