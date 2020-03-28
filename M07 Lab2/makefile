CC = g++
CFLAGS = -Wall -c std=c++14
EXENAME = M07

defualt: main.o Person.o
	$(CFLAGS) $(CC) -o $(EXENAME)
main.o: main.cpp
	$(CFLAGS) main.cpp
Person.o: Person.cpp
	$(CFLAGS) Person.cpp
