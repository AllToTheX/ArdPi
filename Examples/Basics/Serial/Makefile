# MFRC522 makefile

CC = g++

# Include directory
INC_DIR = ../../..

# Compile flags
CXXFLAGS = -Wall -g $(INC_DIR:%=-I%)

# Include directory
VPATH = $(INC_DIR)

# Combine objects
OBJS = main.o Arduino.o

# Compile and link
main: $(OBJS)
	$(CC) -o main $(OBJS)

# Dependencies
main.o : Arduino.h

#cleanup
clean:
	rm -f main *.o