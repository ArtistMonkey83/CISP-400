CC = g++
CCFLAGS = -c -Wall -std=c++14
EXENAME = M07

default: main.o ComplexPlane.o
	$(CC) main.o ComplexPlane.o -o $(EXENAME)
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp
ComplexPlane.o: ComplexPlane.cpp
	$(CC) $(CCFLAGS) ComplexPlane.cpp
ZoomWindow.o: ZoomWindow.cpp
		$(CC) $(CCFLAGS) ZoomWindow.cpp
run:
	./$(EXENAME)
