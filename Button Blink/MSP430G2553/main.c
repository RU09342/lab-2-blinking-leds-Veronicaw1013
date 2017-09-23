#include <msp430.h>

void delay_ms(unsigned int ms ){// Not really a milliseconds delay!
unsigned int i;
for (i = 0; i < ms; i++){
__delay_cycles(500);
}
}
void do_led( int led, int delay ) {
    P1OUT ^= led;
    delay_ms( delay );
}
void main(void) {
    PM5CTL0 &= ~LOCKLPM5;
    WDTCTL = WDTPW + WDTHOLD;       // Hold the WDT (WatchDog Timer)
    P1DIR |= BIT0 + BIT1;// Setup the appropriate output bits
    P5DIR &= ~BIT5;
    P5REN ^= BIT5;
    P5OUT ^= BIT5;

    while(1) {
        if (!(P5IN & BIT5)){      // If not (port one input AND bit3 (sw1))
            do_led( BIT1, 2000 );   // Turn on LED 2
        }
        else{              // Otherwise...
            do_led( BIT0, 1000 );    // Turn on LED 1
        }
    }
}