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

// Macros
#define F(c) c


typedef enum ePinMode = {
	INPUT, OUTPUT
} ePinMode;

typedef enum ePinLevel = {
	HIGH, LOW
}ePinLevel;

void pinMode(int, ePinMode);
void digitalWrite(int, ePinLevel);

// Serial class
// Prints serial data to command prompt instead of serial port.
class Serial {
	
public:
	// calls used
	void print(char *);
	void println(char *);
	
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
};

#endif /* defined(____Arduino__) */
