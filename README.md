# ArdPi
Wrapper for running basic Arduino libraries on Raspberry Pi

Initialy created for using the RC552 NFC Reader/writer library for Arduino on the Raspberry Pi running Raspbian.

To enbale SPI on Raspbian:

Run `sudo raspi-config` and enable SPI in the advanced menu.


To use, create a Serial and SPI instance:
`Serial Serial;`
`SPI SPI;`

You're good to go.

Remember to run your program susing sudo, the GPIO and SPI need root access.

Pinout:
- MISO	GPIO9
- MOSI	GPIO10
- CLK	GPIO11

Examples:
- CS	GPIO8
- RESET	GPIO25
