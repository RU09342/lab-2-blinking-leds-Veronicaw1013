#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= BIT6;                  // configure P1.6 as output
    P1DIR |= BIT0;                  // configure P1.0 as output

    volatile unsigned int i;   // volatile to prevent optimization


    while(1)
    {

        P1OUT ^= BIT6;   // toggle P1.6

        for(i=10000; i>0; i--){
        if(i % 1000 == 0){
            P1OUT ^= BIT0;
        }
    }
}
}

