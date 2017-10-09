#include <msp430.h>

void delay_ms(unsigned int ms )//create a function that takes in an input ms
{
unsigned int i;//create integer i
for (i = 0; i < ms; i++)//start for loop, initialize i as 0, run if i < ms, increment i each iteration
{
__delay_cycles(500);//delay execution of next instruction by 500 cycles
}
}
void do_led( int led, int delay ) // create a function that takes in an input of an led and delay
{
    P1OUT ^= led;// sets which led to toggle
    delay_ms( delay );// sets input to delay_ms
}
void main(void) 
{
    PM5CTL0 &= ~LOCKLPM5;//disable high impedance mode
    WDTCTL = WDTPW + WDTHOLD;      // stop watchdog timer 
    P1DIR |= BIT0 + BIT1;// sets pins 1.0 and 1.1 as outputs
    P5DIR &= ~BIT5;//sets pin 1.5 as input
    P5REN |= BIT5;// enable pin 1.5 resistor
    P5OUT |= BIT5;// tell the resistor to pull up

    while(1)//infinite loop
		{
        if (!(P5IN & BIT5))// if the button is pressed
		{      
            do_led( BIT1, 2000 );  // run do_led with input BIT1 and 2000
        }
        else
		{              // Otherwise...
            do_led( BIT0, 1000 );    // run do_led with input BIT0 and 1000
        }
    }
}
