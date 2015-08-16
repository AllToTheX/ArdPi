# MFRC522 makefile

CC = g++
CFLAGS = -Wall -g

BUILD_DIR = ./build

# Arduino Wrapper directory
WRAP_DIR = ../../..

INC_DIRS = $(WRAP_DIR)

# This makes sure the compile step includes the directories
CXXFLAGS = $(INC_DIRS:%=-I%)

# Objects to build
WRAP_OBJS = Arduino.o SPI.o

# Combine objects
OBJS = main.o $(WRAP_OBJS:%.o=$(WRAP_DIR)/%.o)

# Link
main: $(OBJS)
	$(CC) $(OBJS)  -o main

# pull dependency info from .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
$(BUILD_DIR)%.o: %.c
	$(CC) -c $(CFLAGS) $*.cpp -o $*.o
	$(CC) -MM $(CFLAGS) $*.cpp > $*.d

#cleanup
clean:
	rm -f $(WRAP_DIR)/*.o $(WRAP_DIR)/*.d
	rm -f main *.o *.d