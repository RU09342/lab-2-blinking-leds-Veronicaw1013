#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT0;                  // set pin 1.0 as output
    P4DIR |= BIT7;                  // set pin 4.7 as output

   int i = 0;  // create integer i
   int j = 0;// create integer j


    while(1)//infinite loop
    {
        i ++;//increment i
        j++;//increment j
        if(i>30000)//sets delay rate 
        {i=0;P1OUT^=BIT0;}// reset i, toggle bit 0
        if(j>10000)//sets delay rate 
        {j=0;P4OUT^=BIT7;}// reset j, toggle bit 7
        }
    }
