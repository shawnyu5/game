#purpose of the file: to compile quiz
#date: 2021-08-18
#-------------------------------------------------
    
quiz: main.o quiz.o 
	 g++ -Wall -g -o quiz main.o quiz.o  && ./quiz  | tee output.txt

clean:
	rm -f *.o output.txt quiz

valgrind: quiz
	valgrind -s --leak-check=full --track-origins=yes ./quiz

c: quiz
	./quiz  | tee output.txt

#--------------------------------------------
main.o: main.cpp 
	g++ -c main.cpp

quiz.o: quiz.cpp quiz.h
	g++ -c quiz.cpp

