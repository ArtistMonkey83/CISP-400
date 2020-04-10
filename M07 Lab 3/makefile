CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = M07Lab3

default: main.o Person.o
	$(CC) main.o Person.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
Lines_window.o: Lines_window.cpp
	$(CC) $(CCFLAGS) Lines_window.cpp

run:
	./$(EXENAME)
