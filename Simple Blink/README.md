# Simple Blink 
## Veronica Williams, October 9, 2017, Code Updated: October 8, 2017
This code blinks one of the on-board LEDs at a 50% duty cycle for each of the MSP430 development boards. 

## Libraries for the MSP430
Msp430.h is a general header file that includes all the header files for boards in the MSP430 family. When creating a new project there is a pull down menu that will allow you to choose which board you are actually using. 

## General Format
The watchdog timer must be turned off for the five boards. 

WDTCTL = WDTPW | WDTHOLD;

For the MSP430FR2311, MSP430FR5994, and MSP430FR6989, the GPIO power-on default high-impedance mode must also be disabled.

PM5CTL0 &= ~LOCKLPM5;

The LEDs were configured as outputs depending on the pin numbers for each of the boards. The different cases for each board can be seen in the next section. Generally, PxDIR sets the pins as input or output, where PxDIR = 0 sets an input and PxDIR = 1 sets an output. An integer "i" was created in order to use it for counting.

volatile unsigned int i;

An infinite loop was also created so the code within the loop will run forever. 

while(1){}

or

for(;;)
  
Inside the loop is where the LED is being toggled so it can blink on the boards. The various cases for each board can be seen in the next section. Generally, PxOUT contains the value to be output from the port. When I/O is configured to output mode: 0b = output is low, 1b = output is high. When I/O configured to input mise and pullups/pulldowns enabled: 0b = pulldown selected, 1b = pullup selected. A for loop is used to start "i" equal to 10000, and the for loop will run as long as i >0. After each iteration "i" will decrement. 

for(i=10000; i>0; i--);

or

i = 100000;      

do i--;

while(i != 0);

## Specific Code for Each Board
### MSP430G2553 where pin 1.6 is one of the LEDs-

Configure LED as output: P1DIR |= BIT6;

Toggle LED: P1OUT ^= BIT6;

### MSP430FR6989 where pin 9.7 is one of the LEDs-

Configure LED as output: P9DIR |= BIT7; 

Toggle LED: P9OUT ^= BIT7; 

### MSP430FR5994 where pin 1.1 is one of the LEDs-

Configure LED as output:  P1DIR |= BIT1; 

Toggle LED: P1OUT ^= BIT1; 

### MSP430FR2311 where pin 1.1 is one of the LEDs-

Configure LED as output:  P1DIR |= 0x01; 

Toggle LED: P1OUT ^= 0x01; 

### MSP430FR5529 where pin 1.1 is one of the LEDs-
Configure LED as output:  P1DIR |= 0x01; 
Toggle LED: P1OUT ^= 0x01; 



