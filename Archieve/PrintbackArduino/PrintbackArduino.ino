/*Commputer:
 * 0: -15v
 * 1: +15v
 * RS232
 * 4 USB WIRE: PWR RX TX GND
 * 
 * Arduio:
 * 0: 0v
 * 1: 5v
 * 
 * 4 USB WIRE: PWR TX RX GND(arduino TX- computer RX)
 */
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
char c;
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){ // while not available look for it
 char c = Serial.read();
 Serial.println(c);
}
Serial.flush();
}
