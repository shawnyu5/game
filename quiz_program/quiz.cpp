#include <iostream>
#include <string>
#include "quiz.h"

using namespace std;

//asks the user the question, returns true if user got answer correct, else false
bool Question::askQuestion()
{
    cout << '\n';
    cout << m_question << endl;

    //prints out the possible choices
    for(int i = 0; i < m_choices.size(); i++)
    {
        cout << i+1 << ". " << m_choices[i] << '\n';
    }

    cout << endl;

    int user_guess{0};
    cout << "Your Answer (enter number): ";
    cin >> user_guess;

    cout << '\n';

    if (user_guess == m_correct_answer)
    {
        cout << "***Correct! +10 points***" << endl;
        cout << endl;
        return true;
    }
    else
    {
        cout << endl;
        cout << "***Incorrect***" << endl;
        cout << endl;
        return false;
    }
}

Question::Question(string question, std::vector<string>choices, int correct_answer)
{
    //set question
    m_question = question;

    //add multiple choice choices to vector
    for (int i = 0; i < choices.size(); i++)
    {
        m_choices.push_back(choices[i]);
    }

    //set correct answer
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
    cout << "Your Total Score is " << getTotalScore() << endl << endl;

    if (m_total_score >= 70)
    {
        cout << "Great you passed!" << endl;
        cout << "CONGRATS! " << endl;
    }
    else
    {
        cout << "Sorry, you did not pass..." << endl << endl;
    }
}

//runs the quiz
void Quiz::run(Quiz& quiz)
{
    cout << "********** WELCOME TO THE C++ QUIZ! **********" << "\n\n"
        << "There are " << quiz.getQuestions().size() << " questions in this quiz, each question is worth 10 marks. You must score more than 70 marks to pass. Good luck!" << "\n\n";

    cout << "Press Enter to start the quiz..." << endl;
    cin.get();

    system("clear");

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
