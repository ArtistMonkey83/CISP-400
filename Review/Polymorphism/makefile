CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = Polymorphism

default: main.o Employee.o
	$(CC) main.o Employee.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
Employee.o: Employee.cpp
	$(CC) $(CCFLAGS) Employee.cpp

clean:
	rm *o $(EXENAME)

run:
	./$(EXENAME)
