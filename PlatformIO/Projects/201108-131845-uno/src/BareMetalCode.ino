#include <Arduino.h>
void setup()
{
DDRD = DDRD | 0xF0; // digital pins 4-7 map to register D, 
                    // bits 4-7. 0xF0 = 0b1111 0000 where 
                    // a 1 defines the pin as output. Using 
                    // the bitwise OR (|) allows the remaining 
                    // bits to be unaffected and avoid 
                    // unwanted operation and only set 
                    // the 4 pins we want. You could write 
                    // DDRD = 0xnn, (where n is any hex digit) 
                    // but there is no way of knowing how 
                    // the other bits will be affected. 
                    // It may do nothing, it may not.

DDRB = DDRB & 0xF0; // digital pins 8-11 map to register B0-3. 
                    // Using 0xF0 again, but now 0 is an input. 
                    // We use bitwise AND (&) to leave 
                    // the remaining bits in the register alone.
}
void loop()
{
PORTD = PINB << 4; // write the status of the switches on 
                   // PINB to the LEDs on PORTD, but bit 
                   // shifted left by 4 bits. So RB3-0 map 
                   // to RD7-4.
}
