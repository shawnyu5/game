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
    //the answers to the question
    string m_question;

    //possible choices to the question
    std::vector<string> m_choices;

    //the correct answer
    int m_correct_answer = 0;

    //default constuctor
    Question()
    {}

    //custom constuctor sets a single question
    Question(string question, std::vector<string>choices, int correct_answer);

    //asks the current question
    bool askQuestion ();
};

//manages the questions
class Quiz
{
private:
    //the questions
    std::vector<Question> m_questions;

    //user total score
    int m_total_score = 0;

public:
    void addQuestion(const Question& obj);

    //adds score passed in to the total score
    void addScore(int score);

    //return the vector of questions
    std::vector<Question> getQuestions() const;

    //returns the current total score
    int getTotalScore() const;

    //tells the user if they passed the quiz or not
    void validate();

    //runs the quiz
    void run(Quiz& quiz);
};

