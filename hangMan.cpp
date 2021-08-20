//Date: 2021-07-17
//---------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string_view>
#include <fstream>
#include "hangMan.h"
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
    void HangMan::getWordFromFile()
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

    //allows user to set a new word as the correct answer
    void HangMan::setWord()
    {
        cout << "New Word: ";
        std::cin >> m_word;

        std::ofstream file;
        file.open(".word.txt", std::ofstream::out | std::ofstream::trunc);
        file << m_word;

        cout << "New Word \"" << m_word << "\" set" << endl;
    }

    //set number of attemps allowed
    void HangMan::setAttempt()
    {
       cout << "How many attemps are allowed? (There are " << m_letter_count << " letters in answer)" << endl;
       string attemps;
       bool valid = false;
       while(!valid)
       {
           std::getline(std::cin, attemps);
           //if an invalid value is entered, throw error and ask user for input again
           try
           {
               m_attempt = stoi(attemps);
               if (m_attempt < m_letter_count)
               {
                   cout << "Too few attempts given! There are " << m_letter_count << " letters in the answer" << endl;
                   valid = false;
               }
               else
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

    //set number of hints
    void HangMan::setHints()
    {
        cout << "How many hints would you like to give?" << endl;
        bool valid = false;
        while(!valid)
        {
            std::cin >> m_hints;
            if (m_hints >= m_letter_count)
            {
                cout << "too many hints!" << endl;
            }
            else
            {
                valid = true;
            }
        }

        //adds the number of words to the vector
        std::vector<int> vec;
        for (int i = 0; i < m_letter_count; i++)
        {
            vec.push_back(i);
        }
        std::random_shuffle(vec.begin(), vec.end());

        //reveal the hints
        for (int i = 0; i < m_hints; i++)
        {
            std::list<string>::iterator it = m_correct.begin();
            int index = vec[i];

            //move to the index randomly generated and insert answer before the index
            std::advance(it, index);
            char letter = m_word[index];
            string str;
            str = letter;
            str = str;
            m_correct.insert(it, str);

            //then erase the index that it replaced
            m_correct.erase(it);
            //also erase that word from the correct word list
            m_word[index] = '#';
        }
    }

    //function checks of the game has been complete
    bool HangMan::win()
    {
        //keeps the status of the game, win/lose
        bool win = false;

        for(auto& i : m_word)
        {
            if(i == '#')
            {
                win = true;
            }
            else
            {
                //if one real letter is detected, it means the game has not been finished, then don't bother keep checking
                win = false;
                break;
            }
        }

        //if the user has gotten all the letters correct, don't bother checking for attemps
        if(win)
        {
            cout << "Congratulations!!!" << endl;
            return true;
        }
        else if (m_attempt == 0)
        {
            cout << "Out of attempts!" << endl;
            win = false;
        }
        return win;
    }


    //a single attempt
    bool HangMan::attempt()
    {
        //if the user has won, then return control back to main
        if(win())
        {
            return true;
        }

        string temp_guess;
        cout << "Your Guess: ";
        std::cin.clear();
        std::getline(std::cin, temp_guess);
        //std::cin >> temp_guess;

        const char* guess = temp_guess.c_str();

        for(int i = 0; i < m_letter_count; i++)
        {
            if (guess[0] ==  m_word[i])
            {
                cout << "***Correct Guess!!!***" << endl;
                cout << "---------------------------" << endl;
                std::list<string>::iterator it = m_correct.begin();

                //move to the iterator to where the Correct letter count is found
                std::advance(it, i);

                //insert correct letter at the position
                m_correct.insert(it, string(1, guess[0]));

                //then erase the index that it replaced
                m_correct.erase(it);

                //set the found index to an invalid value, as to the algorithm not flag repeat letters
                m_word[i] = '#';

                //stop after an single letter is found. So if there are multiple occurances of the guessed letter, they will not be both revealed
                break;
            }
        }

        m_attempt--;
        //clear screen after ever attempt
        system("clear");
        display(cout);
        return false;
    }

    //runs this game
    void HangMan::run()
    {
        //local object
        HangMan game;

        //retrieve the correct word
        game.getWordFromFile();

        //how many attemps are allowed by the user
        game.setAttempt();
        game.setHints();
        game.display(cout);

        //keep playing until attemp returns true
        while(!game.attempt());

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


