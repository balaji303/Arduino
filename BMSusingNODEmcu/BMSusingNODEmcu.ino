#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

WiFiClient client;

String thingSpeakAddress= "http://api.thingspeak.com/update?";
String writeAPIKey;
String tsfield1Name;
String request_string;

HTTPClient http;

void setup()
{
    WiFi.disconnect();
   WiFi.begin("wifiUSERname","wifiPASSword"); //Your WiFi username and password
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }

}


void loop()
{
int volt=analogRead(A0);
volt=map(volt,0,1024,0,12);
    if (client.connect("api.thingspeak.com",80)) {
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "YOUR_KEY_HERE"; //Your Write API key
      request_string += "&";
      request_string += "field2";
      request_string += "=";
      request_string += volt;
      http.begin(request_string);
      http.GET();
      http.end();

    }
    delay(5000);

}
