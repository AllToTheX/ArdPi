//
//  main.cpp
//  Arduino_wrapper
//
//  Created by Allex Veldman on 16/08/15.
//  Copyright (c) 2015 Allex Veldman. All rights reserved.
//

#include <stdio.h>
#include "Arduino.h"

void setup(void)
{
	// Do your setup stuff here
}

void loop(void)
{
	Serial.print("This is a const string");
	Serial.println();
	Serial.println("This as well, but with a newline added");
	int value = 112;
	Serial.print(value);
	Serial.println();
	Serial.println(++value);
	delay(1000);
}

hardwareSerial Serial;

int main(int argc, char *argv[])
{
	
	setup();
	
	while (1) {
		loop();
	}
	
	
	
	return 0;
}