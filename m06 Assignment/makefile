CC = g++
CFLAGS = -Wall -c -std=c++14
EXENAME= M06

default: main.o PolygonMatrix.o Matrix.o
	$(CC) main.o PolygonMatrix.o Matrix.o -o $(EXENAME)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
PolygonMatrix.o: PolygonMatrix.cpp
	$(CC) $(CFLAGS) PolygonMatrix.cpp
Matrix.o: Matrix.cpp
	$(CC) $(CFLAGS) Matrix.cpp

clean:
	rm *o $(EXENAME)
run:
	./$(EXENAME)
