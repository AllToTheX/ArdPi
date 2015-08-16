//
//  SPI.cpp
//  
//
//  Created by Allex Veldman on 12/08/15.
//
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/spi/spidev.h>
#include <linux/types.h>
#include <unistd.h>
#include <syslog.h>
#include "SPI.h"

static const char *device = "/dev/spidev0.0";

// SPI functions

// Initialize SPI interface
// SPI Mode 3, 8bits
void hardwareSPI::begin(void)
{
	int ret;
	int mode = SPI_MODE_3;
	bits = 8;
	speed = 500000;
	
	file = open(device, O_RDWR);
	if (file <= 0) {
		printf("can't open device\n");
		abort();
	}
	
	// Set SPI mode
	ret = ioctl(file, SPI_IOC_WR_MODE, &mode);
	if (ret == -1) {
		printf("can't set spi mode\n");
		abort();
	}
	
	ret = ioctl(file, SPI_IOC_RD_MODE, &mode);
	if (ret == -1) {
		printf("can't get spi mode\n");
		abort();
	}
	
	// Set bits per word
	ret = ioctl(file, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1) {
		printf("can't set bits per word\n");
		abort();
	}
	
	ret = ioctl(file, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1) {
		printf("can't get bits per word\n");
		abort();
	}
	
	// Set max speed
	ret = ioctl(file, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1) {
		printf("can't set max speed hz\n");
		abort();
	}
	
	ret = ioctl(file, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1) {
		printf("can't get max speed hz\n");
		abort();
	}
	
	openlog("slog", LOG_PID|LOG_CONS, LOG_USER);
	syslog(LOG_DEBUG, "spi mode: %d\n", mode);
	syslog(LOG_DEBUG,"max speed: %d Hz (%d KHz)\n",speed, speed/1000);
	closelog();
}

void hardwareSPI::setBitOrder(char order)
{
	
}

void hardwareSPI::setDataMode(char mode)
{
	
}

unsigned char hardwareSPI::transfer(unsigned char data)
{
	int ret;
	
	unsigned char rx;
	
	struct spi_ioc_transfer tr =
	{
		tr.tx_buf = (unsigned long)&data,
		tr.rx_buf = (unsigned long)&rx,
		tr.len = 1,
		tr.delay_usecs = 0,
		tr.speed_hz = speed,
		tr.bits_per_word = bits,
	};
	ret = ioctl(file, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1) {
		printf("can't send spi message\n");
		abort();
	}
	
	return rx;
}

void hardwareSPI::end(void)
{
	close(file);
}

