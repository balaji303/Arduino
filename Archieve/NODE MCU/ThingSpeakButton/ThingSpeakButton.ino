/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

int  ButtonState;
WiFiClient client;

String thingSpeakAddress= "http://api.thingspeak.com/update?";
String writeAPIKey;
String tsfield1Name;
String request_string;

HTTPClient http;

void setup()
{
  pinMode(16, INPUT);
ButtonState = digitalRead(16);
  delay(1000);
  WiFi.disconnect();
   WiFi.begin("Thanushiya","krithi202003");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
Serial.begin(9600);
}


void loop()
{

    ButtonState = digitalRead(16);
    delay(500);
    Serial.println(ButtonState);
    if (client.connect("api.thingspeak.com",80)) {
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "17PVANOFRG2N9WUL";
      request_string += "&";
      request_string += "field1";
      request_string += "=";
      request_string += ButtonState;
      http.begin(request_string);
      http.GET();
      http.end();

    }
    delay(1000);

}
