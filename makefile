#purpose of the file: to compile hangman
#date: 2021-07-17
#-------------------------------------------------
hangMan: hangMan.o main.o
	 g++ -Wall -g -o hangMan hangMan.o main.o && ./hangMan  | tee output.txt

clean:
	rm -f *.o hangman

valgrind: hangman
	valgrind -s --leak-check=full --track-origins=yes ./hangMan

c: hangMan
	./hangMan  | tee output.txt

#--------------------------------------------------

main.o: main.cpp
	g++ -c main.cpp

hangMan.o: hangMan.cpp hangMan.h
	g++ -std=c++17 -c hangMan.cpp

#get word functions correctly, gets the correct number of words

testing.o: testing/testing.cpp
	g++ -c testing/testing.cpp
