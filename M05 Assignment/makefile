CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = M05

default: main.o Topograph.o
	$(CC) $(CCFLAGS) main.o Topograph.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
Topograph.o: Topograph.cpp
	$(CC) $(CCFLAGS) Topograph.cpp
clean:
	rm *.o $(EXENAME)
run:
	./$(EXENAME)
