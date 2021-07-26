// Not Working
#include <ESP8266WiFi.h>
int  i;
WiFiServer server(80);

void setup()
{
  i = analogRead(A0);
Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
  Serial.println("Start");
   WiFi.begin("ChaosFather","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffer");
  }
  Serial.println("Success");
  Serial.println("IP");
  Serial.println((WiFi.localIP().toString()));
  server.begin();
}
void loop()
{
    WiFiClient client=server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.flush();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
      client.println("<title>SenSor Network</title>");
    client.println("</head>");
    client.println("<body>");
      i = analogRead(A0);
      client.println("<h1 style=""color:#ff0000"">");
      client.println("LDR value is ");
      client.println("</h1>");
      client.println("<span style=""color:#000000;font-size:14px"">");
      client.println(i);
      client.println("</span>");
      client.println("<h2 style=""color:#ffcc00"">");
      client.println((millis()));
      client.println("</h2>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(1);
}
