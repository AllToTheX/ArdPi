CXX = g++
CXXFLAGS = -Wall -c

all: main

main: main.o Arduino.o SPI.o MFRC522.o
	$(CXX) main.o Arduino.o SPI.o MFRC522.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Arduino.o: Arduino.cpp
	$(CXX) $(CXXFLAGS) Arduino.cpp

SPI.o: SPI.cpp
	$(CXX) $(CXXFLAGS) SPI.cpp

MFRC522.o: MFRC522.cpp
	$(CXX) $(CXXFLAGS) MFRC522.cpp

clean:
	rm *.o main