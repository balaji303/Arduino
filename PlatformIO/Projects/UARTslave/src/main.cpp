#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial softSerial(10,11);
void setup() {
  // put your setup code here, to run once:
  softSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
softSerial.write("Hello, World");
delay(1000);
}