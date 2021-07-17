# Hang man

First entering the game, prompt user to enter a word, or play game
  * Store user entered word in a hidden text file

## Select word

Take in user input. Store word in text file and overwrite previous entry
(`file.open(".word.txt", std::ofstream::out | std::ofstream::truncate`)

Then begin game

## Start playing

A one argument constructor that takes in a word, and sets the word to the word
passed in. As well as set the length of the word.

The class will also have a list that is used for display purposes. It will
contain the template for the correct number of letters. So every time the user
gets a letter correctly, it is inserted into the list

Read from hidden text file for correct word
  * `getWord()` - reads from a hidden file and sets `m_word` to that word read i.
    It has to read only a SINGLE word. so use `cin`

Count how many letters in word, using `string::length()` and display to user in
the formate:

```text
Letters: 5                 Attemps allowed: 6

_ _ _ _ _
```

On each iteration:

  * Ask for user input
      * compare user input againest all letters in word. use `std::string_view`?
      Create a function responsible for comparsion
      * if letter is **correct**, display letter at position (function for
      display)
      * If **incorrect**, tell user letter is incorrect and decrease counter.

Repeat until user gets the correct word or attempt runs out.

`getLetter()`

Ask user for a single letter guess. Function should only read in 1 letter.
(`std::getline(cin, letter, 1`).

After letter is read in, use string view to compare the letter with the correct
word. If it's a match, insert the letter into the list at the same index where
the match is found. 
   * Use a local counter to keep track of the current index

`display()`

Displays to the user the number of words in the correct word, number of attempt
left.
