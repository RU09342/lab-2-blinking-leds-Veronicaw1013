#include <msp430.h>

void main(void)
{
    PM5CTL0 &= ~LOCKLPM5;//disable the GPIO power on default high impedance mode
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P9DIR |= BIT7;                  // set pin 9.7 as output
    P1DIR |= BIT0;                 // set pin 1.0 as output

   int i = 0;   // create integer i
   int j = 0;// create integer j


    while(1)//infinite loop
    {
        i ++;//increment i
        j++;//increment j
        if(i>30000)//sets delay rate 
        {i=0;P9OUT^=BIT7;}// reset i, toggle bit 7
        if(j>10000)//sets delay rate 
        {j=0;P1OUT^=BIT0;}// reset j, toggle bit 0
        }
    }
