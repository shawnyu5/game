#define _CRT_SECURE_NO_WARNINGS
#ifndef HANGMAN_H_
#define HANGMAN_H_
#include <iostream>
#include <string>
#include <utility>
#include <list>
using std::cout;
using std::endl;
using std::string;

namespace sdds
{
    class HangMan
    {
    private:
        //the correct word
        string m_word{};

        //number of words in a correct word
        int m_letter_count{0};

        //number of attemps allowed
        int m_attempt{0};

        //number of hints given
        int m_hints{0};

        //the hangMan prompt displayed to the user for entry
        std::list<std::string> m_correct;
    public:
        HangMan()
        {}

        //1 arg constructor, sets the correct word
        HangMan(string word);

        //gets the word from hidden file
        void getWordFromFile();

        //displays game instructions
        void instructions();

        //allows user to set a new word as the correct answer
        void setWord();

        //set number of attemps allowed
        void setAttempt();

        //set number of hints
        void setHints();

        //represents a single attempt
        bool attempt();

        //function checks of the game has been complete
        bool win();

        //runs this game.
        static void run();

        //display
        void display(std::ostream& os);
    };
}
#endif
