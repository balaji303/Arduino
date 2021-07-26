#include <ESP8266WiFi.h>

IPAddress staticIP667_10(192,168,1,10);
IPAddress gateway667_10(192,168,1,1);
IPAddress subnet667_10(255,255,255,0);

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
  Serial.println("Start");
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffer");
  }
  Serial.println("Host name:");
  Serial.println((WiFi.hostname()));
  Serial.println("Local ip:");
  Serial.println((WiFi.localIP().toString()));
  Serial.println("Static");
  WiFi.config(staticIP667_10, gateway667_10, subnet667_10);
  Serial.println((WiFi.localIP().toString()));
//  if (!client) { return; }
////  while(!client.available()){  delay(1); }
////  Serial.println((client.available()));

}
void loop()
{
}
