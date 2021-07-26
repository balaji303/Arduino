/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(9600);
  WiFi.disconnect();
  delay(5000);
   WiFi.begin("JINKALALA","BALAJIbalaji");
  Serial.println("START");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffer");

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
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    if (i == "ON") {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println(analogRead(A0));
      client.println("</html>");
      client.stop();
      delay(1);
      delay(1000);

    } else {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println(analogRead(A0));
      client.println("</html>");
      client.stop();
      delay(1);
      delay(1000);

    }

}
