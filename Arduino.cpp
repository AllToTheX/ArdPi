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

void digitalWrite(int pin, ePinLevel level)
{
	static const char s_values_str[] = "01";
 
	char path[VALUE_MAX];
	int fd;
 
	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_WRONLY);
	if (fd == -1) {
		printf("Failed to open gpio %d for writing!\n", pin);
		abort();
	}
 
	if (write(fd, &s_values_str[LOW == value ? 0 : 1], 1) != 1) {
		printf("Failed to write value!\n");
		abort();
	}
 
	close(fd);
	return(0);
}

// Serial class functions
void Serial::print(char *c)
{
	cout << c;
}

void Serial::println(char *c)
{
	cout << c << endl;
}