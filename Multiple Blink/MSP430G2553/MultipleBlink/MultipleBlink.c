#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT6;                  // set pin 1.6 as output
    P1DIR |= BIT0;                  // set pin 1.0 as output

   int i = 0;   // create integer i
   int j = 0; // create integer j


    while(1)//infinite loop
    {
        i ++;//increment i
        j++;//increment j
        if(i>30000)//sets delay rate 
        {i=0;P1OUT^=BIT6;}// reset i, toggle bit 1
        if(j>10000)//sets delay rate 
        {j=0;P1OUT^=BIT0;}// reset j, toggle bit 0
        }
    }



