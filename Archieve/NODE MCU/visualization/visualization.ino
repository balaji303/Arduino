#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
int  i;
WiFiServer server(80);
WiFiClient client;
String thingSpeakAddress= "http://api.thingspeak.com/update?";
String writeAPIKey;
String tsfield1Name;
String request_string;
HTTPClient http;
void setup()
{
  i = 0;
Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("ChaosFather","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffer");
  }
  Serial.println("Connected");
  server.begin();
}
void loop()
{
    i = (random(0,10));
    if (client.connect("api.thingspeak.com",80)) {
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "VK9C9HSJHKVQK84G";
      request_string += "&";
      request_string += "field1";
      request_string += "=";
      request_string += i;
      http.begin(request_string);
      http.GET();
      http.end();
      delay(15000);
    }
}
