
default: main.o String.o
	g++ main.o String.o -o M08
main.o: main.cpp String.h
	g++ -c  -Wall -std=c++14 main.cpp
String.o: String.cpp String.h
	g++ -c -Wall -std=c++14 String.cpp
clean:
	rm *.o M08
run:
	./M08
