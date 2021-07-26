// nOt working
#include <ESP8266WiFi.h>
IPAddress staticIP484_101(191,161,1,101);
IPAddress gateway484_101(192,162,1,102);
IPAddress subnet484_101(255,255,255,0);

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
//  Serial.print("Local IP");
//  Serial.println((WiFi.localIP().toString()));
//  Serial.print("Mask");
//  Serial.println((WiFi.subnetMask().toString().c_str()));
//  Serial.print("Gateway IP:");
//  Serial.println((WiFi.gatewayIP().toString().c_str()));
//  Serial.print("Host name");
//  Serial.println((WiFi.hostname()));
//  Serial.println("Client avalable");
//  Serial.print((client.available())); Client not declared
//  Serial.print("MAc address");
//  Serial.println((WiFi.macAddress().c_str()));
//  Serial.println(" END of Orginal ");
  delay(5000);
  Serial.println("Group la Doup ");
  WiFi.config(staticIP484_101, gateway484_101, subnet484_101);
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
  Serial.println("THE END");
}
void loop()
{
}
