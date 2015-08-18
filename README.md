# ArdPi
Wrapper for running basic Arduino libraries on Raspberry Pi

Initialy created for using the RC552 NFC Reader/writer library for Arduino on the Raspberry Pi running Raspbian.

To enbale SPI on Raspbian:

Run `sudo raspi-config` and enable SPI in the advanced menu.


To use, create a Serial and SPI instance:
`Serial Serial;`
`SPI SPI;`

You're good to go.

Remember to run your program using sudo, the GPIO and SPI need root access.
