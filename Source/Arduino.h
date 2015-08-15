//
//  Arduino.h
//  
//
//  Created by Allex Veldman on 12/08/15.
//
//

#ifndef ____Arduino__
#define ____Arduino__

#define PROGMEM

#include <stdio.h>

// Macros
#define F(c) c

// Redefines
typedef unsigned char byte;
typedef unsigned int word;
typedef const char __FlashStringHelper;

typedef enum ePinMode {
	INPUT, OUTPUT
}ePinMode;

#define IN INPUT
#define OUT OUTPUT

typedef enum ePinLevel {
	HIGH, LOW
}ePinLevel;

typedef enum eType {
	HEX, DEC, OCT
}eType;

void pinMode(int, ePinMode);
void digitalWrite(int, ePinLevel);
char digitalRead(int);
void delay(word ms);

// Serial class
// Prints serial data to command prompt instead of serial port.
class Serial {
	
public:
	// calls used
	void print(char *);
	void print(char , eType);
	void print(byte);
	void println(char *);
	void println(void);
	void println(byte);
	void println(__FlashStringHelper *c);
	
	// calls not implemented
	void available(void);
	void begin(void);
	void end(void);
	void find(void);
	void findUntil(void);
	void flush(void);
	void parseFloat(void);
	void parseInt(void);
	void peek(void);
	void read(void);
	void readBytes(void);
	void readBytesUntil(void);
	void readString(void);
	void readStringUntil(void);
	void setTimeout(void);
	void write(void);
	void serialEvent(void);
private:
};

Serial Serial;

#endif /* defined(____Arduino__) */
