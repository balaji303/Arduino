/*
 * Blink an LED by bit masking
 * The on-board LED  on the Arduino UNO is at PortB 5.
 */

 #define MASK(x) ((unsigned char)(1<<x))

void setup() {
  // put your setup code here, to run once:
DDRB |= MASK(5);  //The LED pin is output. Mask: 00100000
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB |= MASK(5); //Turn LED ON
  delay(1000);
  PORTB &= ~MASK(5); //Turn LED OFF
  delay(1000);
}
