#include <ESP8266WiFi.h>
int  NumOFnetwork;
String  hard;
int counter;
int counter_inc;
void setup()
{
  NumOFnetwork = 0;
  hard = "";
  Serial.begin(9600);
  WiFi.disconnect();
  delay(5000);
  NumOFnetwork = (WiFi.scanNetworks());
  Serial.println((millis()));
  Serial.println("Availble network");
  Serial.println(NumOFnetwork);
  counter_inc = 1;
  if (1 > NumOFnetwork) {
    counter_inc = -counter_inc;
  }
  for (counter = 1; counter_inc >= 0 ? counter <= NumOFnetwork : counter >= NumOFnetwork; counter += counter_inc) {
    Serial.print(counter);
    Serial.print(".WIFI SSID=");
    delay(300);
    Serial.println((WiFi.SSID(counter) ));
    Serial.print("  WIFI RSSI=");
    delay(300);
    Serial.println((WiFi.RSSI(counter) ));
    hard = (WiFi.SSID(counter) );
    Serial.print("  WIFI Type=");
    delay(300);
    if (WiFi.encryptionType(counter)==ENC_TYPE_TKIP) {
      Serial.println("WPA");
   
    }
    else if (WiFi.encryptionType(counter)==ENC_TYPE_CCMP) {
      Serial.println("WPA2");
    }
    else {
      Serial.println("HaHaHahAhAhAhA");
    }
    if (hard == "JINKALALA") {
      Serial.println("Gotcha!");
      Serial.println("Connecting to  jinx");
       WiFi.begin("JINKALALA");
      while ((!(WiFi.status() == WL_CONNECTED))){
        delay(300);
        Serial.println("buffer");
      }
      Serial.println("Success");
      Serial.println("!@#$%^&*()*&^%$#@!");
      break;

    }
    else {
      Serial.println("IN Search  of Hotspot");
    }
    Serial.println("!@#$%^&*()*&^%$#@!");
    delay(1000);
  }
}
void loop()
{
}
