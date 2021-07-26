#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
Wire.begin(4);
if(Wire.available()){}
else
Wire.write("123Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
}

/*
 * void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("123Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
}
 */
