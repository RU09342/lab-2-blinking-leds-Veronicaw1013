# Button Blink 
## Veronica Williams, October 9, 2017, Code Updated: October 8, 2017 

This code toggles one LED when the button is pressed and toggles another LED when the button is pressed. 

## Libraries for the MSP430
Msp430.h is a general header file that includes all the header files for boards in the MSP430 family. When creating a new project there is a pull down menu that will allow you to choose which board you are actually using. 

## General Format

For the MSP430FR5994,   ,two functions were made that will be called in the main function. First, delay_ms was created that takes in an unsigned integer ms as an input. Within the function, an integer "i" is created to use for counting. A for loop is used which initializes "i" as 0, runs if i < the input ms, and "i" is incremented at each iteration. The function __ delay_cycles was then used to delay the execution of the next instruction. This sets the delay of the LED blink.  

void delay_ms(unsigned int ms )//create a function that takes in an input ms
{
unsigned int i;//create integer i
for (i = 0; i < ms; i++)//start for loop, initialize i as 0, run if i < ms, increment i each iteration
{
__ delay_cycles(500);//delay execution of next instruction by 500 cycles
}
}

Next, do_led was created which takes in an integer led, and an integer delay. This function allows the LED to blink. The function toggles the LED based on which LED was set on the input. It also calls on delay_ms to set the delay between blinks. 

void do_led( int led, int delay ) // create a function that takes in an input of an led and delay
{
    P1OUT ^= led;// sets which led to toggle
    delay_ms( delay );// sets input to delay_ms
}

The watchdog timer must be turned off for the five boards. 

WDTCTL = WDTPW | WDTHOLD;

For the MSP430FR2311, MSP430FR5994, and MSP430FR6989, the GPIO power-on default high-impedance mode must also be disabled.

PM5CTL0 &= ~LOCKLPM5;

The LEDs were configured as outputs depending on the pin numbers for each of the boards. The different cases for each board can be seen in the next section. The button was also set as an input. The different cases for each board can also be seen in the next section.
 
An infinite loop was also created so the code within the loop will run forever. 

while(1){}


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

