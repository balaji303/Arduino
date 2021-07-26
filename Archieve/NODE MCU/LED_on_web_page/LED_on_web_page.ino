#include <ESP8266WiFi.h>
String  i;
WiFiServer server(80);
void setup()
{
  i = "";
Serial.begin(9600);
pinMode(16, OUTPUT);
  WiFi.disconnect();
  Serial.println("Starting");
  delay(5000);
   WiFi.begin("ChaosFather","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffer");
  }
  Serial.println("Success");
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
      digitalWrite(16,HIGH);
      Serial.println("LED ON");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED ON");
      client.println("</html>");
      client.stop();
      delay(1);
      delay(2000);

    } else {
      digitalWrite(16,LOW);
      Serial.println("LED OFF");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED OFF");
      client.println("</html>");
      client.stop();
      delay(1);
      delay(2000);

    }

}
