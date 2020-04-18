CC = g++
CCFLAGS = -c -Wall -std=1c++14
EXENAME = FileIO

default: main.o PolyMorphism.o
	$(CC) main.o PolyMorphism.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
PolyMorphism.o: PolyMorphism.cpp
	$(CC) $(CCFLAGS) PolyMorphism.cpp

clean:
	rm *o $(EXENAME)

run:
	./$(EXENAME)
