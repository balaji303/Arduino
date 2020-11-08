

void setup() {
  // put your setup code here, to run once:
  DDRB |= 0x20; //pinMode(13,OUTPUT);
  /*
  DDRB means Port B Data Direction Register, which is set to 0b100000
  Here I am setting PIN 13 as OUTPUT by writing 1 on DDRB register
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB |= 0x20; //digitalWrite(13,HIGH);
  /*
  PORTB means Data Register, which is set to 0b100000
  Here I am setting PIN 13 as HIGH or High voltage(+5) is passed to  that PIN
  */
  delay(1000);
  PORTB &= ~(0x20); //digitalWrite(13,LOW);
  /*
  PORTB means Data Register, which is set to 0b000000, so that other PINs are not modified
  Here I am setting PIN 13 as LOW or LOW voltage(GND) is passed to  that PIN
  */
  delay(1000);
}
