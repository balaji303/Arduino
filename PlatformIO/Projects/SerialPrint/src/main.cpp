#include <Arduino.h>
String ch;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Welcome to the jungle");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()!=0){
    ch=Serial.readString();
    Serial.print("The entered value is ");
    Serial.print(ch);
    Serial.println(" ");
    delay(100);
  }
}