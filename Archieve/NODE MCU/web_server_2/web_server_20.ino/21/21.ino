//by Kathirmani from techmemicro and tuniot
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//WiFiServer server(80);
ESP8266WebServer server(80);
String page = "";
String page1 = "";

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
  Serial.println("Start");
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffer");

  }
  delay(1000);
  Serial.println("Success");
  Serial.println((WiFi.localIP().toString()));
  
  page = "<p> Hello </p>";
  server.on("/", [](){
    server.send(200, "text/html", page);
  });
  page1 = "<p> Patter hi </p>";
  server.on("/hi", [](){
    server.send(500, "text/html", page1);
  }); 
  server.begin();
  
}


void loop()
{

server.handleClient();
}
