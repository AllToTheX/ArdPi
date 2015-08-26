//
//  Arduino.h
//  
//
//  Created by Allex Veldman on 12/08/15.
//
//

#ifndef ____Arduino__
#define ____Arduino__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define PROGMEM			// Disable the PROGMEM macro, everything is stored in data memory

// Redefines
typedef unsigned	char	byte;
typedef signed		char	int8_t;
typedef unsigned	int		word;
typedef const		char	__FlashStringHelper;
typedef bool				boolean;

typedef enum ePinMode {
	INPUT, OUTPUT
}ePinMode;

#define IN INPUT
#define OUT OUTPUT

typedef enum ePinLevel {
	LOW, HIGH
}ePinLevel;

typedef enum eType {
	HEX, DEC, OCT
}eType;

void pinMode(int, ePinMode)__attribute__((weak));
void digitalWrite(int pin, ePinLevel level)__attribute__((weak));
void _digitalWrite(int pin, int level);
char digitalRead(int)__attribute__((weak));
void delay(word ms);

// Program memory macro overwrites
byte pgm_read_byte(const byte *);
const char * F(const char *c);

// Serial class
// Prints serial data to command prompt instead of serial port.
class hardwareSerial {
public:

	// calls used
	void print(byte *);
	void print(const char *);
	void print(char , eType);
	void print(int);
	void print(byte);
	void println(char *);
	void println(void);
	void println(int);
	void println(byte);
	void println(__FlashStringHelper *c);
	void begin(int);
	
	// calls not implemented
	void available(void);
	
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
	
	// Bypasses 'while(!Serial)' segments as we don't need to init the serial port
	bool operator!(){
		return false;
	}
}extern Serial;

#endif /* defined(____Arduino__) */
