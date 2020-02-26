CC = g++
CFLAGS = -c -Wall -std=c++14
EXENAME = M04

default: main.o Matrices.o
	$(CC) Matrices.o main.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
Matrices.o: Matrices.cpp
	$(CC) $(CFLAGS) Matrices.cpp
clean:
	rm *o $(EXENMAE)
run:
	./$(EXENAME)
