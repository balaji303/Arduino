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
   WiFi.begin("Thanushiya","krithi202003");
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
      request_string += "5O5I97N93C4RO1E2";
      request_string += "&";
      request_string += "field2";
      request_string += "=";
      request_string += volt;
      http.begin(request_string);
      http.GET();
      http.end();

    }
    delay(2000);

}
