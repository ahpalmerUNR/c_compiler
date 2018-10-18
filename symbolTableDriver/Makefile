CPP=g++
CPPFLAGS = -std=c++11

all: driver

driver: symboltable.o
	$(CPP) $(CPPFLAGS) driver.cpp symboltable.o -o driver

symboltable.o: ../src/symboltable.h
	$(CPP) $(CPPFLAGS) -c ../src/symboltable.cpp

clean:
	-rm -f *.o driver driverOut.txt

