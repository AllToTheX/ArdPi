//
//  main.cpp
//  Arduino_wrapper
//
//  Created by Allex Veldman on 15/08/15.
//  Copyright (c) 2015 Allex Veldman. All rights reserved.
//

#include <stdio.h>
#include "iostream"
#include "Arduino.h"
#include "SPI.h"

int main(int argc, char *argv[])
{
	Serial Serial;
	SPI SPI;
	
	Serial.println(F("Hello World"));
	
	pinMode(8,OUTPUT);
	digitalWrite(8, LOW);
	
	SPI.begin();
	while(1)
	{
		char value = SPI.transfer(0xAA);
		printf("0x%X\n",value);
		delay(1000);
	}
	
	SPI.end();
	
	
	return 0;
}