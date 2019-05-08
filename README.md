# ArdPi
Wrapper for running basic Arduino libraries on Raspberry Pi

Initially created for using the RC552 NFC Reader/writer library for Arduino on the Raspberry Pi running Raspbian.

To enable SPI on Raspbian:

Run `sudo raspi-config` and enable SPI in the advanced menu.

Add these to your program:
`hardwareSerial Serial;`
`hardwareSPI SPI;`

You're good to go.

Remember to run your program using sudo, the GPIO and SPI need root access.

Pinout:
- MISO	GPIO9
- MOSI	GPIO10
- CLK	GPIO11

Examples:
- CS	GPIO8
- RESET	GPIO25

