#purpose of the file: to compile hangman
#date: 2021-07-17
#-------------------------------------------------
    
hangman: hangman.o main.o
	 g++ -Wall -g -o hangman hangman.o main.o && ./hangman  | tee output.txt

clean:
	rm -f *.o hangman

valgrind: hangman
	valgrind -s --leak-check=full --track-origins=yes ./hangman

c: hangman
	./hangman  | tee output.txt

#--------------------------------------------------

main.o: main.cpp
	g++ -c main.cpp

hangman.o: hangman.cpp hangman.h
	g++ -c hangman.cpp

#get word functions correctly, gets the correct number of words
getWord_testing: hangman.o getWord.o .word.txt
	g++ hangman.o getWord.o && ./a.out

getWord.o: testing/getWord.cpp
	g++ -c testing/getWord.cpp
