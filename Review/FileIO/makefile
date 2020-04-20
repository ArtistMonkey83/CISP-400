CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = FileIO

default: main.o Point.o
	$(CC) main.o Point.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
Point.o: Point.cpp
	$(CC) $(CCFLAGS) Point.cpp
#YoliesHeadnFoot.o: YoliesHeadnFoot.cpp
	#$(CC) $(CCFLAGS) YoliesHeadnFoot.cpp

clean:
	rm *o $(EXENAME)

run:
	./$(EXENAME)
