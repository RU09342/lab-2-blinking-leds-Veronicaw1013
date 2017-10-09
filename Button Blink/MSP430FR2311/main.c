#include <msp430.h> 
void delay_ms(unsigned int ms )//create a function that takes in an input ms
{
unsigned int i;//create integer i
for (i = 0; i < ms; i++)//start for loop, initialize i as 0, run if i < ms, increment i each iteration
{
__delay_cycles(500);//delay execution of next instruction by 500 cycles
}
}

void main(void)
 {
    PM5CTL0 &= ~LOCKLPM5;//disable high impedance mode
    WDTCTL = WDTPW + WDTHOLD;        // stop watchdog timer  
    P1DIR |= BIT0;// sets pins 1.0 as output
    P2DIR |= BIT0;// sets pins 2.0 as output
    P1DIR &= ~BIT1;//sets pin 1.1 as input
    P1REN |= BIT1;// enable pin 1.1 resistor
    P1OUT |= BIT1;// tell the resistor to pull up

    while(1) //infinite loop
	{
	{
        if (!(P1IN & BIT1))// if the button is pressed
		{      
            P1OUT ^= BIT0;//toggle PIN 1.0
               delay_ms( 2000 );  //sets input to delay_ms
        }
        else
		{              // Otherwise...
            P2OUT ^= BIT0;//toggle PIN 2.0
               delay_ms(1000); //sets input to delay_ms  
        }
    }
}
