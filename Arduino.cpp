//
//  Arduino.cpp
//
// Wrapper for arduino calls so arduino libraries can be used
// on Raspberry Pi.
//
// Only digital pins and SPI is supported for now
//
//  Created by Allex Veldman on 12/08/15.
//
//

#include "Arduino.h"
#include <stream>


// Serial class functions
void Serial::print(char *c)
{
	cout << c;
}

void Serial::println(char *c)
{
	cout << c << endl;
}