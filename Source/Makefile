OBJECTS = Arduino.o

EXEC = main

CXXFLAGS = -Wall

CXX = g++

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(EXEC).cpp -o $(EXEC) $(OBJECTS)

clean:
	rm -f ./*.o