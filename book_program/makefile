#purpose of the file: to compile book
#date: 2021-08-25
#-------------------------------------------------
    
book: book.o main.o 
	 g++ -Wall -g -o book book.o main.o  && ./book  | tee output.txt

clean:
	rm -f *.o output.txt book

valgrind: book
	valgrind -s --leak-check=full --track-origins=yes ./book

c: book
	./book  | tee output.txt

#--------------------------------------------
book.o: book.cpp book.h
	g++ -c book.cpp

main.o: main.cpp 
	g++ -c main.cpp

