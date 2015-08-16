# MFRC522 makefile

CC = g++
CFLAGS = -Wall -g


WRAPPER_PATH = ../..
VPATH = $(SRC_PATH)

# Example files
FILES = main.cpp  MFRC522.cpp

# Wrapper files
WRAPPER_FILES = Arduino.cpp SPI.cpp

# Combine all sources
SOURCES = $(FILES) $(WRAPPER_FILES:%.cpp=$(WRAPPER_PATH)/%.cpp)

all:
	$(CC) $(CFLAGS) -I$(SRC_PATH) $(SOURCES) -o main