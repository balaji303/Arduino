#include <Pinger.h>
#include <PingerResponse.h>

#include <ESP8266WiFi.h>

#include <ESP8266Ping.h>

boolean mypingip(int a, int b, int c, int d)
{
boolean result;
IPAddress remote_ip(a,b,c,d);
result = Ping.ping(remote_ip);
return result;
}

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  Serial.println("Start");
  delay(1000);
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffer");

  }
  Serial.println("Connected");
  Serial.println("PING:192.168.1.1");
  Serial.println((mypingip(192,168,1,1)));
  Serial.println("PING:157.49.209.146");//motog ip 
  Serial.println((mypingip(157,49,209,146)));
  Serial.println("PING:125.99.248.166");//dell303
  Serial.println((mypingip(125,99,248,166)));

}


void loop()
{


}
