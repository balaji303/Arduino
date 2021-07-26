#include "ESP8266WiFi.h"
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(digitalRead(4),BIN);
Serial.println(digitalRead(4),DEC);
Serial.println(digitalRead(4),HEX);
Serial.println(digitalRead(4),OCT);
delay(500);
}
