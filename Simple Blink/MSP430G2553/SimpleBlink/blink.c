#include <msp430.h>				

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= BIT6;					// sets pin 1.6 as output

	volatile unsigned int i;		//create unsigned integer i

	while(1) //infinite loop
	{
		P1OUT ^= BIT6;				// toggle P1.6
		for(i=10000; i>0; i--);     // start for loop, initialize i as 10000, run if i > 0, decrement i each interation 
	}
}
