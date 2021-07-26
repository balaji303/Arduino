#include <ESP8266WiFi.h>

String  ClientRequest;
WiFiServer server(80);

void setup()
{
  ClientRequest = "";

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
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    ClientRequest = (client.readStringUntil('\r'));
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println((random(0,100)));
    client.println("</html>");
    client.stop();
    delay(1);
    client.flush();

}
