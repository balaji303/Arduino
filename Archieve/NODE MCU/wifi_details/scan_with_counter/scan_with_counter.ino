#include <ESP8266WiFi.h>
int network;
int counter;
int counter_end;
int counter_inc;
void setup()
{
  Serial.begin(300);
  WiFi.disconnect();
  delay(5000);
  network = (WiFi.scanNetworks());
  Serial.println((millis()));
  Serial.println("Availble network");
  Serial.println(network);
  counter_end = network;
  counter_inc = 1;
  if (1 > counter_end) {
    counter_inc = -counter_inc;
  }
  for (counter = 1;counter_inc >= 0 ? counter <= network : counter >= network; counter += counter_inc) {
    Serial.print("WIFI SSID--");
    delay(500);
    Serial.println((WiFi.SSID(counter) ));
    Serial.print("WIFI RSSI--");
    delay(500);
    Serial.println((WiFi.RSSI(counter) ));
      }
}
void loop()
{
}
