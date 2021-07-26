//Works with the APP buttonMCU from mitApp inventor
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
   WiFi.begin("JINKALALA","BALAJIbalaji");
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
//    client.flush(); //used to filter the notification
    if (i == "ON") {
      digitalWrite(16,LOW);
      Serial.println("LED ON");
      delay(200);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED ON");
      client.println("</html>");
//      client.stop();
      delay(1);
//      delay(2000);
    }
    if (i == "OFF") {
      digitalWrite(16,HIGH);
      Serial.println("LED OFF");
      delay(200);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED OFF");
      client.println("</html>");
//      client.stop();
      delay(100);
//      delay(2000);

    }
}
