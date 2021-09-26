//purpose of this file: Run quiz program
//Date: 2021-08-18
//---------------------------------
#include "quiz.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

int main () {

    Quiz quiz;

    //char temp[1000];
    //std::cin.get(temp, 1000);
    //char* answers = new char[954];
    //strcpy(answers, temp);

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
