CC = g++
CCFLAGS =  -c -Wall std=c++14
EXENAME = M07Lab2

default: main.o Person.o
	$(CC) main.cpp Person.cpp -o $(EXENAME)
main.o: main.cpp
	$(CCFLAGS) main.cpp
Person.o: Person.cpp
	$(CCFLAGS) Person.cpp
run:
	./$(EXENAME)
