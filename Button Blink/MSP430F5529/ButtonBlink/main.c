#include <msp430.h> 

void delay_ms(unsigned int ms ){// Not really a milliseconds delay!
unsigned int i;
for (i = 0; i < ms; i++){
__delay_cycles(500);
}
}

void main(void) {
   // PM5CTL0 &= ~LOCKLPM5;
    WDTCTL = WDTPW + WDTHOLD;       // Hold the WDT (WatchDog Timer)
    P1DIR |= BIT0;// Setup the appropriate output bits
    P4DIR |= BIT7;
    P2DIR &= ~BIT1;
    P2REN ^= BIT1;
    P2OUT ^= BIT1;

    while(1) {
        if (!(P2IN & BIT1)){      // If not (port one input AND bit3 (sw1))
            P1OUT ^= BIT0;
               delay_ms( 2000 );   // Turn on LED 2
        }
        else{              // Otherwise...
            P4OUT ^= BIT7;
               delay_ms(1000);   // Turn on LED 1
        }
    }
}
