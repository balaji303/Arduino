/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

String  sensor20;
String  sensor10;
IPAddress staticIP113_50(192,168,1,50);
IPAddress gateway113_50(192,168,1,1);
IPAddress subnet113_50(255,255,255,0);

WiFiServer server(80);

String  httpurl;
String  TheHiddenAnswerOfClient;
HTTPClient http;

String SendWithAnswer(String IPcache, String monmessagecache) {
httpurl = "http://";
httpurl+=IPcache;
httpurl+="/";
httpurl+=monmessagecache;
http.begin(httpurl);
http.GET();
TheHiddenAnswerOfClient = (http.getString());
http.end();
return TheHiddenAnswerOfClient;
}

void setup()
{
  sensor20 = "";

sensor10 = "";

Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("JINKALALA","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("Buffer");

  }
  Serial.println("Connected");
  WiFi.config(staticIP113_50, gateway113_50, subnet113_50);
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
    sensor20 = (SendWithAnswer("192,168,1,20",""));
    sensor20.remove(0, 25);
    sensor20.remove(sensor20.length()-11,11);
    sensor10 = (SendWithAnswer("192,168,1,10",""));
    sensor10.remove(0, 25);
    sensor10.remove(sensor10.length()-11,11);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
      client.println("<title>SenSor Network</title>");
    client.println("</head>");
    client.println("<body>");
      client.println("<h1 style=""color:#ff0000"">");
      client.println("Welcome");
      client.println("</h1>");
      client.println("<span style=""color:#993399;font-size:25px"">");
      client.println("Start");
      client.println("</span>");
      client.println("<span style=""color:#333300;font-size:20px"">");
      client.println((millis()));
      client.println("</span>");
      client.println("<h2 style=""color:#006600"">");
      client.println("Sensor10");
      client.println("</h2>");
      client.println("<span style=""color:#000000;font-size:14px"">");
      client.println(sensor10);
      client.println("</span>");
      client.println("<h2 style=""color:#006600"">");
      client.println("Sensor20");
      client.println("</h2>");
      client.println("<span style=""color:#000000;font-size:14px"">");
      client.println(sensor20);
      client.println("</span>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(1);

}
