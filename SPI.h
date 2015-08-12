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

// SPI class
// Transfers data to Raspberry SPI bus
class SPI {
	int file;
	int speed;
	int bits;
	
public:
	// calls used
	void setBitOrder(char);
	void setDataMode(char);
	unsigned char transfer(unsigned char);
	
	// calls not implemented yet
	void begin(void);
	void end(void);
	void beginTransfer(void);
	void endTransfer(void);
	void setClockDivider(void);
	void usingInterrupt(void);	
};
#endif /* defined(____SPI__) */
