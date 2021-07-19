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
        string m_word{};
        int m_letter_count{0};
        int m_attempt{0};
        std::list<std::string> m_correct;
    public:
        HangMan()
        {}

        //1 arg constructor
        HangMan(string word);

        //gets the word from hidden file
        void getWordFromFile();

        //set number of attemps allowed
        void setAttempt();

        //set number of hints
        void setHints();

        //a single attempt
        void attempt();

        //display
        void display(std::ostream& os);
    };
}
#endif
