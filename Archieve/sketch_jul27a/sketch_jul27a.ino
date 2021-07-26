#include <ESP8266WiFi.h>
String  i;
WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
i = "";

  Serial.println("Start");
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("ChaosFather","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Connecting");

  }
  Serial.println("Connected success");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    i = (client.readStringUntil('\r'));
    client.println("HTTP/1.1 200 OK");
    //client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("Welcome");
    client.println("</html>");
    client.stop();//removing this may work but only few times
    delay(1);
}
