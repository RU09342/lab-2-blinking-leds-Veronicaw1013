# Simple Blink 
## Veronica Williams, October 9, 2017, Code Updated: October 8, 2017
This code blinks one of the on-board LEDs at a 50% duty cycle for each of the MSP430 development boards. 

## Libraries for the MSP430
Msp430.h is a general header file that includes all the header files for boards in the MSP430 family. When creating a new project there is a pull down menu that will allow you to choose which board you are actually using. 

## General Format
The watchdog timer must be turned off for the five boards. 
WDTCTL = WDTPW | WDTHOLD;



The LEDs were configured as outputs depending on the pin numbers for each of the boards. An integer "i" was created in order to use it for counting. 
