//Has both client and server so not working
#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

String  i;
WiFiServer server(80);

String  httpurl;
HTTPClient http;

void setup()
{
  Serial.begin(9600);
i = "";

  Serial.println("Start");
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("JINKALALA","BALAJIbalaji");
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
    httpurl = "http://";
    httpurl+=(WiFi.localIP().toString());
    httpurl+="/";
    httpurl+="Yes";
    http.begin(httpurl);
    http.GET();
    http.end();
    i = (client.readStringUntil('\r'));

}
