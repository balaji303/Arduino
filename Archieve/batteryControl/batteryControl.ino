//not working
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
String  ClientRequest;
//WiFiServer server(80);
String page="";
String data="";
void setup()
{
Serial.begin(9600);
pinMode(16, OUTPUT);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("Buffer");
  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  server.on("/", [data](){
    page = "<h1>Batterylevel</h1><h3>Data:</h3> <h4>"+String(data)+"</h4>";
    server.send(200, "text/html", page);
  });
      if (data.toInt() > 50) {
      digitalWrite(16,HIGH);
      delay(3000);
      digitalWrite(16,LOW);
      Serial.println("Above 90");
    } 
    else {
      digitalWrite(16,LOW);
      Serial.println("Below 90");
    }
  
  server.begin();
}
void loop()
{
  delay(3000);

    server.handleClient();
}
