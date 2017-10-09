# Button Blink 
## Veronica Williams, October 9, 2017, Code Updated: October 8, 2017 

This code toggles one LED when the button is pressed and toggles another LED when the button is pressed. 

## Libraries for the MSP430
Msp430.h is a general header file that includes all the header files for boards in the MSP430 family. When creating a new project there is a pull down menu that will allow you to choose which board you are actually using. 

## General Format

For the MSP430FR5994 and MSP430G2553,two functions were made that will be called in the main function. First, delay _ ms was created that takes in an unsigned integer ms as an input. Within the function, an integer "i" is created to use for counting. A for loop is used which initializes "i" as 0, runs if i < the input ms, and "i" is incremented at each iteration. The function "delaycycles" was then used to delay the execution of the next instruction. This sets the delay of the LED blink.  

void delay _ ms(unsigned int ms )//create a function that takes in an input ms

	{

	unsigned int i;//create integer i

	for (i = 0; i < ms; i++)//start for loop, initialize i as 0, run if i < ms, increment i each iteration

	{

	__delay_cycles(500); //delay execution of next instruction by 500 cycles
	}
	}

Next, do _ led was created which takes in an integer led, and an integer delay. This function allows the LED to blink. The function toggles the LED based on which LED was set on the input. It also calls on delay_ms to set the delay between blinks. 

void do _ led( int led, int delay ) // create a function that takes in an input of an led and delay

	{

    	P1OUT ^= led;// sets which led to toggle
    
   	delay _ ms( delay );// sets input to delay _ ms
    
	}

For the other boards only the delay _ ms function was used. 

The watchdog timer must be turned off for the five boards. 

WDTCTL = WDTPW | WDTHOLD;

For the MSP430FR2311, MSP430FR5994, and MSP430FR6989, the GPIO power-on default high-impedance mode must also be disabled.

PM5CTL0 &= ~LOCKLPM5;

The LEDs were configured as outputs depending on the pin numbers for each of the boards. The different cases for each board can be seen in the next section. The button was also set as an input. The different cases for each board can also be seen in the next section.Generally, PxDIR sets the pins as input or output, where PxDIR = 0 sets an input and PxDIR = 1 sets an output. PxREN activates either a pull up or pull down resistor. PxDIR = 0 sets pullup or pulldown resistor disabled, PxDIR = 1 sets pullup or pulldown resistors enabled. PxOUT also has to be set to either 0 for a pulldown resistor or 1 for a pullup resistor.
 
An infinite loop was also created so the code within the loop will run forever. 

while(1){}

Within the loop is a code to blink both LEDs on the boards. If the button is pressed it will toggle one of the LEDs at a delay specified by the delay _ ms function. If the button is not pressed, the other LED will toggle at a delay specified by delay _ ms. Generally, PxOUT contains the value to be output from the port. When I/O is configured to output mode: 0b = output is low, 1b = output is high. 

if (!(P5IN & BIT5))// if the button is pressed

	{      
		
        do_led( BIT1, 2000 );  // run do_led with input BIT1 and 2000
	    
        }
	
        else
	
	{              // Otherwise...
		
        do_led( BIT0, 1000 );    // run do_led with input BIT0 and 1000
	
	}
            
or

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


## Specific Code for Each Board
### MSP430G2553 where pins 1.6 and 1.0 are LEDs, pin 1.3 is a button-

Configure LEDs as outputs: P1DIR |= BIT6; P1DIR |= BIT0; 

Configure button as input: P1DIR &= ~BIT3; P1REN |= BIT3; P1OUT |= BIT3;

Toggle LEDs: P1OUT ^= BIT6; P1OUT^=BIT0;

### MSP430FR6989 where pins 9.7 and 1.0 are LEDs, pin 1.1 is a button-

Configure LEDs as outputs: P9DIR |= BIT7; P1DIR |= BIT0;  

Configure button as input: P1DIR &= ~BIT1; P1REN |= BIT1; P1OUT |= BIT1;

Toggle LEDs: P9OUT ^= BIT7; P1OUT^=BIT0;

### MSP430FR5994 where pin 1.1 and 1.0 are LEDs, pin 5.5 is a button-

Configure LEDs as outputs:  P1DIR |= BIT1; P1DIR |= BIT0;  

Configure button as input: P5DIR &= ~BIT5; P5REN |= BIT5; P5OUT |= BIT5;

Toggle LEDs: P1OUT ^= BIT1; P1OUT^=BIT0;

### MSP430FR2311 where pin 1.0 and 2.0 are LEDs, pin 1.1 is a button-

Configure LEDs as outputs:  P1DIR |= 0x01; P2DIR |= BIT0; 

Configure button as input: P1DIR &= ~BIT1; P1REN |= BIT1; P1OUT |= BIT1;

Toggle LEDs: P1OUT ^= 0x01; P2OUT^=BIT0;

### MSP430FR5529 where pin 1.0 and pin 4.7 are LEDs, pin 2.1 is a button-
Configure LEDs as outputs:  P1DIR |= 0x01;  P4DIR |= BIT7;  

Configure button as input: P2DIR &= ~BIT1; P2REN |= BIT1; P2OUT |= BIT1;

Toggle LEDs: P1OUT ^= 0x01; P4OUT^=BIT7;

