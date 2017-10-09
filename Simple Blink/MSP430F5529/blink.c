#include <msp430.h>				

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output

	volatile unsigned int i;		//create unsigned integer i

	while(1)//infinite loop
	{
		P1OUT ^= 0x01;				// toggle P1.0
		for(i=10000; i>0; i--);     // start for loop, initialize i as 10000, run if i > 0, decrement i each interation 
	}
}
