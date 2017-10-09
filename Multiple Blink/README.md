# Multiple Blink 
## Veronica Williams, October 9, 2017, Code Updated: October 8, 2017 

This code blinks two of the on-board LEDs at a 50% duty cycle for each of the MSP430 development boards.

## Libraries for the MSP430
Msp430.h is a general header file that includes all the header files for boards in the MSP430 family. When creating a new project there is a pull down menu that will allow you to choose which board you are actually using. 

## General Format
The watchdog timer must be turned off for the five boards. 

WDTCTL = WDTPW | WDTHOLD;

For the MSP430FR2311, MSP430FR5994, and MSP430FR6989, the GPIO power-on default high-impedance mode must also be disabled.

PM5CTL0 &= ~LOCKLPM5;

The LEDs were configured as outputs depending on the pin numbers for each of the boards. The different cases for each board can be seen in the next section. Generally, PxDIR sets the pins as input or output, where PxDIR = 0 sets an input and PxDIR = 1 sets an output. Two integers "i" and "j" were created in order to use for counting.

 int i =0;
 
 int j=0;
 
An infinite loop was also created so the code within the loop will run forever. 

while(1){}
  
Inside the loop is where the two LEDs are toggled so they can blink on the boards. The various cases for each board can be seen in the next section. Generally, PxOUT contains the value to be output from the port. When I/O is configured to output mode: 0b = output is low, 1b = output is high. When I/O configured to input mise and pullups/pulldowns enabled: 0b = pulldown selected, 1b = pullup selected. Both "i" and "j" are incremented first within the loop. If i > 30000, then "i" is reset and one of the LEDs is toggled. If j >10000, then "j" is reset and the other LED is toggled. Different values other than 30000 and 10000 could be used in order to get different blink speeds. 

i ++;

j++;

if(i>30000)

{i=0;P1OUT^=BIT6;}

if(j>10000)

{j=0;P1OUT^=BIT0;}

## Specific Code for Each Board
### MSP430G2553 where pins 1.6 and 1.0 are LEDs-

Configure LEDs as outputs: P1DIR |= BIT6; P1DIR |= BIT0; 

Toggle LEDs: P1OUT ^= BIT6; P1OUT^=BIT0;

### MSP430FR6989 where pins 9.7 and 1.0 are LEDs-

Configure LEDs as outputs: P9DIR |= BIT7; P1DIR |= BIT0;   

Toggle LEDs: P9OUT ^= BIT7; P1OUT^=BIT0;

### MSP430FR5994 where pin 1.1 and 1.0 are LEDs-

Configure LEDs as outputs:  P1DIR |= BIT1; P1DIR |= BIT0;  

Toggle LEDs: P1OUT ^= BIT1; P1OUT^=BIT0;

### MSP430FR2311 where pin 1.0 and 2.0 are LEDs-

Configure LEDs as outputs:  P1DIR |= 0x01; P2DIR |= BIT0; 

Toggle LEDs: P1OUT ^= 0x01; P2OUT^=BIT0;

### MSP430FR5529 where pin 1.0 and pin 4.7 are LEDs-
Configure LEDs as outputs:  P1DIR |= 0x01;  P4DIR |= BIT7;  
Toggle LEDs: P1OUT ^= 0x01; P4OUT^=BIT7;


