/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
  Serial.println("Start");
  WiFi.softAP("funny","12345678");
  Serial.println("ip");
  Serial.println((WiFi.softAPIP()));
  
//  Serial.println((client.remoteIP()));

}


void loop()
{
delay(3000);
Serial.println("connected station");
  Serial.println((WiFi.softAPgetStationNum()));
  
}
