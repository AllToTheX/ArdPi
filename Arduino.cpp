//
//  Arduino.cpp
//
// Wrapper for arduino calls so arduino libraries can be used
// on Raspberry Pi.
//
// Only digital pin I/O and Serial is supported for now.
//
// Serial class directs all Serial data to the terminal, Rpi UART is not supported.
//
// Any data originaly stored in program memory will be stored in
// data memory except for 'const'.
//
// You might need to replace <Arduino.h> in your libraries with "Arduino.h"
// or add them to your local include path.
//
//  Created by Allex Veldman on 12/08/15.
//



#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "Arduino.h"

// Exports the GPIO pin file used to write to the pins
static int GPIOExport(int pin)
{
#define BUFFER_MAX 3
	char buffer[BUFFER_MAX];
	ssize_t bytes_written;
	int fd;
 
	fd = open("/sys/class/gpio/export", O_WRONLY);
	if (fd == -1) {
		fprintf(stderr, "Failed to open export for writing!\n");
		return(-1);
	}
 
	bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
	write(fd, buffer, bytes_written);
	close(fd);
	return(0);
}

// Unexports the GPIO file
static int GPIOUnexport(int pin)
{
	char buffer[BUFFER_MAX];
	ssize_t bytes_written;
	int fd;
 
	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd == -1) {
		fprintf(stderr, "Failed to open unexport for writing!\n");
		return(-1);
	}
 
	bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
	write(fd, buffer, bytes_written);
	close(fd);
	return(0);
}

// Sets the pin direction
static int GPIODirection(int pin, int dir)
{
	static const char s_directions_str[]  = "in\0out";
 
#define DIRECTION_MAX 35
	char path[DIRECTION_MAX];
	int fd;
 
	snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
	fd = open(path, O_WRONLY);
	if (fd == -1) {
		fprintf(stderr, "Failed to open gpio direction for writing!\n");
		return(-1);
	}
 
	if (write(fd, &s_directions_str[IN == dir ? 0 : 3], IN == dir ? 2 : 3) == -1) {
		fprintf(stderr, "Failed to set direction!\n");
		return(-1);
	}
 
	close(fd);
	return(0);
}

// Overwrite, sets the pin direction
void pinMode(int pin, ePinMode direction)
{
	if (GPIOExport(pin) == -1 ) {
		printf("Failed to enable pins");
		abort();
	}
	
	if ( GPIODirection(pin, direction) == -1) {
		printf("Failed to set pin directions");
		abort();
	}
}

// Overwrite, writes a value to the pin
void digitalWrite(int pin, ePinLevel level)
{
	static const char s_values_str[] = "01";
 #define VALUE_MAX 30
	char path[VALUE_MAX];
	int fd;
 
	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_WRONLY);
	if (fd == -1) {
		printf("Failed to open gpio %d for writing!\n", pin);
		abort();
	}
 
	if (write(fd, &s_values_str[LOW == level ? 0 : 1], 1) != 1) {
		printf("Failed to write value!\n");
		abort();
	}
 
	close(fd);
}

// Overwrite, reads the pin value
char digitalRead(int pin)
{
	char path[VALUE_MAX];
	char value_str[3];
	int fd;
 
	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_RDONLY);
	if (fd == -1) {
		printf("Failed to open gpio value for reading!\n");
		abort();
	}
 
	if (read(fd, value_str, 3) == -1) {
		printf("Failed to read value!\n");
		abort();
	}
 
	close(fd);
 
	return(atoi(value_str));
}

// Overwrite, delays in ms
void delay(word ms)
{
	usleep(ms * 1000);
}

// Serial class functions, writes to the terminal

// Overwrite, serial needs no setup so do nothing
void hardwareSerial::begin(int x)
{
	
}

// Overwrite, prints a byte array
void hardwareSerial::print(byte *c)
{
	std::cout << c;
}

// Overwrite, prints const arrays
void hardwareSerial::print(const char *c)
{
	std::cout << c;
}

// Overwrite, prints a single byte as an integer
void hardwareSerial::print(byte c)
{
	printf("%i",c);
}

// Overwrite, prints an int as an integer
void hardwareSerial::print(int c)
{
	printf("%i",c);
}

// Overwrite, prints a single byte as the specified type
void hardwareSerial::print(char c, eType type)
{
	switch (type) {
		case HEX:
			printf("%.2X",c);
			break;
		case DEC:
			printf("%i",c);
			break;
		case OCT:
			printf("%o",c);
			break;
  default:
			printf("%i",c);
			break;
	}
}

// Overwrite, print array + newline
void hardwareSerial::println(char *c)
{
	std::cout << c << std::endl;
}

// Overwrite, print newline
void hardwareSerial::println(void)
{
	std::cout << std::endl;
}

// Overwrite, print single byte as integer + newline
void hardwareSerial::println(byte c)
{
	printf("%i\n",c);
}

// Overwrite, print int as integer + newline
void hardwareSerial::println(int c)
{
	printf("%i\n",c);
}

// Overwrite of function that prints strings stored in program memory
void hardwareSerial::println(__FlashStringHelper *c)
{
	std::cout << c << std::endl;
}

// Overwrite of AVR program memory macro, returns the value at address c
byte pgm_read_byte(const byte *c)
{
	return *c;
}

// Overwrite of function thats reads arrays from program memory.
const char * F(const char *c)
{
	return (const char *)c;
}