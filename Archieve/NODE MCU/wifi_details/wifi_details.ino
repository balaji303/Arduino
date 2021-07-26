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
  Serial.print("Local IP");
  Serial.println((WiFi.localIP().toString()));
  Serial.print("Mask");
  Serial.println((WiFi.subnetMask().toString().c_str()));
  Serial.print("Gateway IP:");
  Serial.println((WiFi.gatewayIP().toString().c_str()));
  Serial.print("Host name");
  Serial.println((WiFi.hostname()));
//  Serial.println("Client avalable");
//  Serial.print((client.available())); Client not declared
  Serial.print("MAc address");
  Serial.println((WiFi.macAddress().c_str()));
  Serial.print("The END");
  delay(10000);
}
void loop()
{
}
