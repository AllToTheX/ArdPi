//
//  SPI.h
//  
//
//  Created by Allex Veldman on 12/08/15.
//
//

#ifndef ____SPI__
#define ____SPI__

#include <stdio.h>

#define MSBFIRST 0 // does nothing yet
#define SPI_MODE0 0 // does nothing yet

// SPI class
// Transfers data to Raspberry SPI bus
class hardwareSPI {
	int file;
	int speed;
	int bits;
	
public:
	// calls used
	void begin(void);
	void setBitOrder(char);
	void setDataMode(char);
	unsigned char transfer(unsigned char);
	void end(void);
	
	// calls not implemented yet
	
	void beginTransfer(void);
	void endTransfer(void);
	void setClockDivider(void);
	void usingInterrupt(void);	
}extern SPI;

#endif /* defined(____SPI__) */
