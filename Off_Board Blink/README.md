# Off Board Blink
The G2553 was taken off the development board and into a breadboard, where the "Multiple Blink" code was used to blink two offboard LEDs.

See the "Multiple Blink" code for reference.

## Breadboard setup
In order to get the LEDs to function with the G2553 off-board the following had to be accomplished:

•	Proper power being supplied to the processor

•	Proper Reset Circuitry

•	Proper Bypass and Bulk Capacitors as needed

The link for the MSP430G2 User's Guide can be found in the references section. The User's Guide had a circuit diagram as well as capacitor and resistor values for the internal circuitry of the MSP430G2553. This diagram was used to replicate the circuit onto the breadboard. 
A picture of the circuit can be seen in "image1.jpeg" and a video of the code running on the breadboard can be seen in "Video.MOV". 

Nothing was changed in the "Multiple Blink" code to run it on the breadboard.

## References

http://www.ti.com/lit/ug/slau318g/slau318g.pdf
