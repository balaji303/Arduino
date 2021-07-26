uint8_t fvolt; 
void setup() {
  // put your setup code here, to run once:
pinMode(A3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
fvolt = ((1.38/5.0)*255);
/*
1.38 = Required Voltage at the output pin
5.00 = Max. readable voltage
255  = Largest 8 bit value (uint8_t)
*/
analogWrite(11,fvolt);
}
