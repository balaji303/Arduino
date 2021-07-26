#define r 5
#define g 6
#define b 16
char red;
char green;
char blue;
#include "ESP8266WiFi.h"
void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<3;i++){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  delay(500);
}
for(int i=0;i<5;i++){
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
  delay(1000);
}
for(int i=0;i<4;i++){
  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
  digitalWrite(green,LOW);
  delay(800);
}

}
