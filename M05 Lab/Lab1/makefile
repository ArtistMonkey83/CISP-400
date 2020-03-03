CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME= M05Lab1

default: main.o Points.o
	$(CC)  main.o Points.o -o $(EXENAME)
main.o: main.cpp
		$(CC) $(CCFLAGS) main.cpp
Points.o:	Points.cpp
	$(CC) $(CCFLAGS) Points.cpp
clean:
	rm*o $(EXENAME)
run:
	./$(EXENAME)
