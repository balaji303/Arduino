#include "ESP8266WiFi.h"
#define RED D5
#define GREEN D6
#define BLUE  D8
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(BLUE,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(RED,LOW);
//digitalWrite(BLUE,LOW);
//digitalWrite(GREEN,LOW);
//delay(1000);
//digitalWrite(RED,HIGH);
//delay(1000);
//digitalWrite(BLUE,HIGH);
//delay(1000);
//digitalWrite(GREEN,HIGH);
//delay(1000);
//digitalWrite(RED,LOW);
//digitalWrite(BLUE,LOW);
//digitalWrite(GREEN,LOW);
//delay(2000);
analogWrite(RED,50);
analogWrite(BLUE,10);
analogWrite(GREEN,105);
}
