//Dont know how to clear request from the browser
#include <ESP8266WiFi.h>

String  i;
String  j;
WiFiServer server(80);

void setup()
{
  i = "";

j = "";

Serial.begin(9600);
  Serial.println("Start");
  WiFi.disconnect();
  delay(5000);
   WiFi.begin("JINKALALA","BALAJIbalaji");
  Serial.println("Start");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Bufferig");

  }
  Serial.println((WiFi.localIP().toString()));
  server.begin();
  Serial.println("Connected");

}


void loop()
{
    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
//    j = (client.remoteIP());
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    j.remove(0, 25);
    j.remove(j.length()-11,11);
    Serial.println(i);
    Serial.println(j);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("Hello");
    client.println("</html>");
    client.stop();
    delay(1);

}
