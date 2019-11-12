#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin(10);
pinMode(13,OUTPUT);
Wire.onRequest(requestEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}

void requestEvent(){
  Wire.write("1234567890\0");
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
}
