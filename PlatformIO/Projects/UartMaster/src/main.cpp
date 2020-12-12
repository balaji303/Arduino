#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial softSerial(10,11);
char ip;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  softSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    ip=Serial.read();
    softSerial.print(ip);
    delay(100);
  }
}