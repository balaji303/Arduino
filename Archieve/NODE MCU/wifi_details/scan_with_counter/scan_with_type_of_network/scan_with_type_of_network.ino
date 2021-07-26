#include <ESP8266WiFi.h>
int  NumOFnetwork;
int counter;
int counter_inc;
void setup()
{
  NumOFnetwork = 0;
Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
  WiFi.begin();
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
    Serial.print(".");
    Serial.print("WIFI SSID=");
    delay(500);
    Serial.println((WiFi.SSID(counter) ));
    Serial.print("  WIFI RSSI=");
    delay(500);
    Serial.println((WiFi.RSSI(counter) ));
    Serial.print("  WIfI Type=");
    delay(500);    
    if (WiFi.encryptionType(counter)==ENC_TYPE_TKIP) {
      Serial.println("WPA");
    } else if (WiFi.encryptionType(counter)==ENC_TYPE_CCMP) {
      Serial.println("WPA2");
    } else {
      Serial.println("HaHaHahAhAhAhA");
   }
       Serial.println("***************");
  }
}
void loop()
{
}
