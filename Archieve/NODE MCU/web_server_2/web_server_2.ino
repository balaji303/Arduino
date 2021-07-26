//WORKIng but no message in browser
#include <ESP8266WiFi.h>

WiFiServer server(80);

void setup()
{
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
    if (!client) { 
      return; 
      Serial.println("No client");
    }
    while(!client.available()){
      delay(1);
      }
    Serial.println((client.readStringUntil('\r')));
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("Hello!");
    client.println("</html>");
    client.stop();
    delay(1);

}
