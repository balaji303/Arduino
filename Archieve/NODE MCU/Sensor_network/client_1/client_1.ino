/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

IPAddress staticIP49_20(192,168,1,20);
IPAddress gateway49_20(192,168,1,1);
IPAddress subnet49_20(255,255,255,0);

WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("my-net","");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("Buffer");

  }
  Serial.println("Connected");
  WiFi.config(staticIP49_20, gateway49_20, subnet49_20);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.flush();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println(analogRead(A0));
    client.println("</html>");
    client.stop();
    delay(1);

}
