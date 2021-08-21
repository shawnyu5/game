//purpose of this file:
//Date: 2021-08-18
//---------------------------------
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using std::cout;
using std::endl;
using std::string;

struct Question
{
    //the question
    string m_question;
    string m_answer_1;
    string m_answer_2;
    string m_answer_3;
    string m_answer_4;

    int m_correct_answer = 0;

    int m_user_guess = 0;

    //default constuctor
    Question()
    {}

    //custom constuctor sets a single question
    Question(string q, string a1, string a2, string a3, string a4, int correct_answer);

    //asks the current question
    bool askQuestion ();
};

//manages a bunch of questions
class Quiz
{
private:
    std::vector<Question> m_questions;
    int m_total_score = 0;

public:
    void addQuestion(const Question& obj);

    //adds score passed in to the total score
    void addScore(int score);

    //return the vector of questions
    std::vector<Question> getQuestions() const;

    //returns the current total score
    int getTotalScore() const;

    //tells the user if they passed or not
    void validate();

    //runs the quiz
    void run(Quiz& quiz);
};

