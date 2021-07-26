#include <ESP8266WiFi.h>
void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
  Serial.println("Start");
   WiFi.begin("ChaosFather","BALAJIbalaji");
  Serial.println("Connecting");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffering");
  }
  Serial.println("Success");
}
void loop()
{
}
