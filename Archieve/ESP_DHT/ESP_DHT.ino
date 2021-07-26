#include "ESP8266WiFi.h"
#include "DHT.h"
DHT dht14(14,DHT11);
void setup()
{
  Serial.begin(9600);
}
void loop()
{
    Serial.println("Temperature");
    Serial.println((dht14.readTemperature( )));
    Serial.println("TEmp in F");
    Serial.println((dht14.readTemperature(true)));
    Serial.println("Humudity");
    Serial.println((dht14.readHumidity( )));
    Serial.println("Humudity in F");
    Serial.println((dht14.readHumidity(true)));
    delay(2000);
}
