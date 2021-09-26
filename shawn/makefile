#purpose of the file: to compile hangman
#date: 2021-07-17
#-------------------------------------------------
game: hangMan.o main.o quiz.o
	 g++ -Wall -g -o game hangMan.o quiz.o main.o && ./game  | tee output.txt

clean:
	rm -f *.o hangman

valgrind: hangman
	valgrind -s --leak-check=full --track-origins=yes ./hangMan

c: hangMan
	./hangMan  | tee output.txt

#--------------------------------------------------

main.o: main.cpp
	g++ -c main.cpp

hangMan.o: hangMan_program/hangMan.cpp hangMan_program/hangMan.h
	g++ -std=c++17 -c hangMan_program/hangMan.cpp

quiz.o: quiz_program/quiz.cpp quiz_program/quiz.h
	g++ -c quiz_program/quiz.cpp

testing.o: testing/testing.cpp
	g++ -c testing/testing.cpp
