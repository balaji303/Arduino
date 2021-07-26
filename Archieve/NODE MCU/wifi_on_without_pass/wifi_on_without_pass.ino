//Not working
#include "ESP8266WiFi.h"
void Network() {
  WiFi.disconnect();
  delay(1000);
  Serial.println("Start");
   WiFi.begin("ChaosFather");
  Serial.println("Connecting");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffering");
  }
  Serial.println("Success");
}
void setup()
{
    Network();
Serial.begin(9600);
}
void loop()
{
}
