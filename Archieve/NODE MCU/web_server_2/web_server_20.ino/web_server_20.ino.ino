//working but not in browser
#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(9600);
  delay(1000);
  WiFi.disconnect();
  Serial.println("Start");
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffer");

  }
  Serial.println("Start");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    client.flush();
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    Serial.println(i);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("Welcome");
    client.println("</html>");
    client.stop();
    delay(1);

}
