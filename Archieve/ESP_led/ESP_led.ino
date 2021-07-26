#include <ESP8266WiFi.h>
void setup() {
  // put your setup code here, to run once:
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(5,HIGH);
 delay(1000);
 digitalWrite(6,HIGH);
 delay(1000);
 digitalWrite(5,LOW);
 delay(1000);
 digitalWrite(6,LOW);
 delay(1000);
}
