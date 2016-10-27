CC=g++
FLAGS=-Wall -std=c++11

all: main

main: main.o Cell.o
	$(CC) $(FLAGS) main.o Cell.o -o main

Cell.o: Cell.cpp
	$(CC) $(FLAGS) -c Cell.cpp


clean:
	rm *.o main
