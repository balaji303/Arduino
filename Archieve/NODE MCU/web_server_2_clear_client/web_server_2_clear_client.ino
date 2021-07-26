#include <ESP8266WiFi.h>

String  clientreq;
WiFiServer server(80);

void setup()
{
  clientreq = "";

Serial.begin(9600);
  WiFi.disconnect();
  delay(5000);
  Serial.println("Start");
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffering");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    clientreq = (client.readStringUntil('\r'));
    Serial.println(clientreq);
    clientreq.remove(0, 25);
    clientreq.remove(clientreq.length()-11,11);
    client.println("HTTP/1.21 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("Hello!");
    client.println("</html>");
//    client.stop();            Adel's mistake is this
    delay(1);

}
