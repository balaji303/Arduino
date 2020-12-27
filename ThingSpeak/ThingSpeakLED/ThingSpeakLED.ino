#include <ESP8266WiFi.h>

#include <ThingSpeak.h>

WiFiClient client;
uint8_t LedState;
void setup()
{
  pinMode(16, OUTPUT);
Serial.begin(9600);
ThingSpeak.begin(client);
  digitalWrite(16,HIGH);
  delay(1000);
  digitalWrite(16,LOW);
  delay(1000);
    digitalWrite(16,HIGH);
  delay(1000);
  digitalWrite(16,LOW);
  WiFi.disconnect();
   WiFi.begin("Thanushiya","krithi202003");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
  }
}


void loop()
{

    LedState=(ThingSpeak.readIntField(1270625,1,"NNX6UN94K5XSDQA8"));
    Serial.println(LedState);
    digitalWrite(16,LedState);
    delay(1000);

}
