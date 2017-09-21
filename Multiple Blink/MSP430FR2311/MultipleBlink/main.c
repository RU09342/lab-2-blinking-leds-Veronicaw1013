#include <msp430.h>

void main(void)
{
    PM5CTL0 &= ~LOCKLPM5;
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P2DIR |= BIT0;                  // configure P1.6 as output
    P1DIR |= BIT0;                  // configure P1.0 as output

   int i = 0;   // volatile to prevent optimization
   int j = 0;


    while(1)
    {
        i ++;
        j++;
        if(i>30000)
        {i=0;P2OUT^=BIT0;}
        if(j>10000)
        {j=0;P1OUT^=BIT0;}
        }
    }



