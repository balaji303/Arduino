//Not working
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 String  i,j;
 int val;
 ESP8266WebServer server(80);

void setup()
{
Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("JINKALALA","BALAJIbalaji");
  Serial.println("START");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("buffer");
  }
  delay(1000);
  Serial.println("Connected");
  Serial.println((WiFi.localIP().toString()));
  delay(1000);
   server.begin();
}
void loop()
{
    val=analogRead(A0);
    delay(100);
    server.handleClient();
    i="<h1><h2>The Data of LDR is</h2><p>"+String(val)+"</p></h1>";
    server.on("/",[](){
      while (true){server.send(200, "text/html", "<h1><h2>The Data of LDR is</h2><p>"+String(val)+"</p></h1>");} delay(1000);
  server.send(200,"text/html",i);
  }
    );
    server.send(200,"text/html","<h1><h2>The Data of LDR is</h2><p>"+String(analogRead(A0))+"</p></h1>");
  
}
