CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = M07Lab2

default: main.o Person.o
	$(CC) main.o Person.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
Person.o: Person.cpp
	$(CC) $(CCFLAGS) Person.cpp

run:
	./$(EXENAME)
