#include <ESP8266WiFi.h>
WiFiClient client;
char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "IQ1B9QRPS28DR3O0";
String tsData;
void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("Start");
   WiFi.begin("ChaosFather","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffer");
  }
  Serial.println("Connected");
  if (client.connect("api.thingspeak.com",80)) {
    Serial.println("Tweet");
    tsData = "api_key="+thingtweetAPIKey+"&status="+"@elonmusk even i am busy boy!...";
    client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(tsData.length());
    client.print("\n\n");
    client.print(tsData);
    delay(5000);
    Serial.println("Tweeting");
  }
  Serial.println("Tweet Completed");
}
void loop()
{
}
