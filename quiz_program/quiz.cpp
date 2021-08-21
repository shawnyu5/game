#include "quiz.h"
#include <iostream>
#include <string>

using namespace std;

//asks the user the question, returns true if user got answer correct, else false
bool Question::askQuestion()
{
    cout << endl;
    cout << m_question << endl;
    cout << "1. " << m_answer_1 << endl;
    cout << "2. " << m_answer_2 << endl;
    cout << "3. " << m_answer_3 << endl;
    cout << "4. " << m_answer_4 << endl;
    cout << endl;

    cout << "What is your answer? (enter number)" << endl;
    cin >> m_user_guess;

    if (m_user_guess == m_correct_answer)
    {
        cout << "***Correct! +10 points" << endl;
        cout << endl;
        return true;
    }
    else
    {
        cout << endl;
        cout << "***Incorrect..." << endl;
        cout << endl;
        return false;
    }
}

Question::Question(string q, string a1, string a2, string a3, string a4, int correct_answer)
{
    m_question = q;
    m_answer_1 = a1;
    m_answer_2 = a2;
    m_answer_3 = a3;
    m_answer_4 = a4;
    m_correct_answer = correct_answer;
}

//adds a question to vector
void Quiz::addQuestion(const Question& obj)
{
    m_questions.push_back(obj);
}

//return the vector of questions
std::vector<Question> Quiz::getQuestions() const
{
    return m_questions;
}

//adds score passed in to the total score
void Quiz::addScore(int score)
{
    m_total_score += score;
}


//returns the current total score
int Quiz::getTotalScore() const
{
    return m_total_score;
}


//tells the user if they passed or not
void Quiz::validate()
{
    cout << "Your Total Score is " << getTotalScore() << " out of 100" << endl;
    cout << endl;

    if (m_total_score >= 70)
    {
        cout << "Great you passed the quiz!" << endl;
        cout << endl;
        cout << " CONGRATS! " << endl;
    }
    else
    {
        cout << "Sorry, you did not pass..." << endl;
        cout << endl;
    }
}

//runs the quiz
void Quiz::run(Quiz& quiz)
{
    cout << "********** WELCOME TO THE C++ QUIZ! **********" << endl;
    cout << endl;

    cout << "Press Enter to start the quiz..." << endl;
    cin.get();


    //loops through all questions and asks them
    for (auto& current : quiz.getQuestions())
    {
        //if user got question correct, askQuestion will return true;
        if (current.askQuestion())
        {
            quiz.addScore(10);
        }
    }

    //tells the user if they failed
    quiz.validate();
}
