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
    WDTCTL = WDTPW + WDTHOLD;       // Hold the WDT (WatchDog Timer)
    P1DIR |= BIT0 + BIT6;// Setup the appropriate output bits
    P1DIR &= ~BIT3;
    P1REN ^= BIT3;
    P1OUT ^= BIT3;

    while(1) {
        if (!(P1IN & BIT3)){      // If not (port one input AND bit3 (sw1))
            do_led( BIT6, 2000 );   // Turn on LED 2
        }
        else{              // Otherwise...
            do_led( BIT0, 1000 );    // Turn on LED 1
        }
    }
}
