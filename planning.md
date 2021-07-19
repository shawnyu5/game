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

### `getHints`

Get from user how many hints to give.

Number of hints has to be less than length of word

Then generate numbers randomly to show the letters of in the word
  * create a vector containing the number length of the word
     * ie if the word is 3 letter long, the vector would contain `1, 2, 3`
  * randomly shuffle the vector. Take the first how ever many numbers as the
  letters to reveal

Count how many letters in word, using `string::length()` and display to user in
the formate:

```text
Letters: 5                 Attemps allowed: 6

_ _ _ _ _
```

### `getLetter()`

Ask user for a single letter guess. Function should only read in 1 letter.
(`std::getline(cin, letter, 1`).

After letter is read in, use string view to compare the letter with the correct
word. If it's a match, insert the letter into the list at the same index where
the match is found. 
   * Use a local counter to keep track of the current index

### `attempt()`

A single attempt of the puzzle

On each iteration:

  * Ask for user input
      * compare user input againest all letters in word. use `std::string_view`?
      * if letter is **correct**, display letter at position
      * If **incorrect**, tell user letter is incorrect and decrease counter

Call `display`

Repeat until user gets the correct word or attempt runs out.

### `whenToStop()`

Function determines of the game should be stooped, either the user ran out of
attempts or won.

If all indexes in `m_word` has been set to an invalid value (`#`), it means all
letters in the correct word has been guessed. And the user **Wins**.

Else if `m_attempt` == 0, then attempts has ran out, and user looses

### `display()`

Displays to the user the number of words in the correct word, number of attempt
left.
