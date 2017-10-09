#include <msp430.h> 

void delay_ms(unsigned int ms ) //create a function that takes in an input ms
{
unsigned int i; //create integer i
for (i = 0; i < ms; i++) //start for loop, initialize i as 0, run if i < ms, increment i each iteration
{
__delay_cycles(500); //delay execution of next instruction by 500 cycles
}
}
void do_led( int led, int delay ) // create a function that takes in an input of an led and delay
{
    P1OUT ^= led; // sets which led to toggle
    delay_ms( delay ); // sets input to delay_ms
}
void main(void) 
{
    WDTCTL = WDTPW + WDTHOLD; // stop watchdog timer      
    P1DIR |= BIT0 + BIT6; // sets pins 1.0 and 1.6 as outputs
    P1DIR &= ~BIT3; //sets pin 1.3 as input
    P1REN |= BIT3; // enable pin 1.3 resistor
    P1OUT |= BIT3; // tell the resistor to pull up

    while(1) //infinite loop
	{
        if (!(P1IN & BIT3)) // if the button is pressed
		{      
            do_led( BIT6, 2000 );  // run do_led with input BIT6 and 2000
        }
        else
		{              // Otherwise...
            do_led( BIT0, 1000 ); // run do_led with input BIT0 and 1000
        }
    }
}
