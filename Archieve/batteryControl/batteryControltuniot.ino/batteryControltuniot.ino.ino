//Battery Boss code
//Low - Rellay Light ON - CONNECTS
//HIGH - Rellay Light OFF - OFF
#include <ESP8266WiFi.h>
String  ClientRequest;
WiFiServer server(80);

void setup()
{
  ClientRequest = "";

Serial.begin(9600);
pinMode(16, OUTPUT);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffer");

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
    ClientRequest.remove(0, 5);
    ClientRequest.remove(ClientRequest.length()-9,9);
    if (ClientRequest.toInt() > 40) {                   //Check this OUT
      digitalWrite(16,HIGH); //LIGHT ON IN RELAY
      Serial.println("Above 40");

    } else {
      digitalWrite(16,LOW); //LIGHT OFF IN RELAY
      Serial.println("Below 40");

    }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println(ClientRequest);
    client.println("</html>");
    delay(100);
    client.flush();
}