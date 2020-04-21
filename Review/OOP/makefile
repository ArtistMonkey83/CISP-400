CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = OOP

default: main.o Car.o
	$(CC) main.o Car.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
Car.o: Car.cpp
	$(CC) $(CCFLAGS) Car.cpp

clean:
	rm *.o $(EXENAME)

run:
	./$(EXENAME)
