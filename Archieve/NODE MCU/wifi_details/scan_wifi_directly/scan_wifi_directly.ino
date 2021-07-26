#include <ESP8266WiFi.h>
void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(5000);
  Serial.println((millis()));
  Serial.println("Availble network");
  Serial.println((WiFi.scanNetworks()));
  Serial.println("WIFI SSID");
  Serial.println((WiFi.SSID((WiFi.scanNetworks())) ));
  Serial.println("WIFI RSSI");
  Serial.println((WiFi.RSSI((WiFi.scanNetworks())) ));
}
void loop()
{
}
