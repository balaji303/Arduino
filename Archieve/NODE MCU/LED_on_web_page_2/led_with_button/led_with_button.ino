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
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffer");

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
    client.flush();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
      client.println("<h1 style=""color:#ff0000"">");
      client.println("Display");
      client.println("</h1>");
    client.println("</head>");
    client.println("<body>");
      client.println("<h1 style=""color:#ff0000"">");
      client.println("Come");
      client.println("</h1>");
      client.println("<a href=");
      client.println("LED=ON");
      client.println("><button>");
      client.println("ON");
      client.println("</button></a>");
      client.println("<a href=");
      client.println("LED=OFF");
      client.println("><button>");
      client.println("OFF");
      client.println("</button></a>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(1);

}
