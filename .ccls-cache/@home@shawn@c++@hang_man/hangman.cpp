//Date: 2021-07-17
//---------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "hangman.h"
using std::cout;
using std::endl;
using std::string;

namespace sdds
{
    //1 arg constructor sets a new word
    HangMan::HangMan(string word)
    {
        m_word = word;
    }

    //gets the word from hidden file
    void HangMan::getWord()
    {
        std::fstream file(".word.txt");
        if(!file.good())
        {
            string error{"bad file"};
            throw error;
        }

        //read in a word from file
        file >> m_word;
        m_letter_count = m_word.length();

        //fill list with underscores
        for (int i = 0; i < m_letter_count; i++)
        {
            m_correct.push_back("_ ");
        }
    }

    //set number of attemps allowed
    void HangMan::setAttempt()
    {
       cout << "How many attemps are allowed?" << endl;
       string attemps;
       bool valid = false;
       while(!valid)
       {
           std::getline(std::cin, attemps);
           //if an invalid value is entered, throw error and ask user for input again
           try
           {
               m_attempt = stoi(attemps);
               valid = true;
           }
           catch(...)
           {
               cout << "invalid entry, please try again" << endl;
               valid = false;
           }
           if (valid == true)
           {
               break;
           }

       }

    }
    //display
    void HangMan::display(std::ostream& os)
    {
        os << "Letters in word: " << m_letter_count << "                 Attemps left: " << m_attempt
            << endl << endl;
        for(auto current : m_correct)
        {
            os << current;
        }
        os << endl;

    }
}


