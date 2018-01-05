CC = g++
CLFAGS = --std=c++11 -Wall  -c
LFLAGS = --std=c++11
CPP = ./src/sudoku.cpp
HEADER = ./src/sudoku.hpp
MAIN = ./src/main.cpp

all: sudoku
	mv sudoku.o main.o ./obj

sudoku: sudoku.o main.o
	$(CC) $(LFLAGS) sudoku.o main.o -o sudoku

sudoku.o: $(HEADER) $(CPP)
	$(CC) $(CLFAGS) $(HEADER) $(CPP)

main.o: $(MAIN)
	$(CC) $(CLFAGS) $(MAIN)

.PHONY: clean doc test

doc:
	doxygen doxyfile

test:
	./test.sh

clean:
	rm -rf *.o sudoku
	rm -rf ./src/*.o
