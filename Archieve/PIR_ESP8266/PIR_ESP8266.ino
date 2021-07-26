#include "ESP8266WiFi.h"
void setup()
{
pinMode(16, INPUT);
Serial.begin(9600);
}
void loop()
{
  Serial.println(digitalRead(16));
  delay(1000);
}
