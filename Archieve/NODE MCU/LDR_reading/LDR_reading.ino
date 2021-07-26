//#include <ESP8266WiFi.h>
void setup()
{
  Serial.begin(9600);

}


void loop()
{

    Serial.println("The value is ");
    Serial.println(analogRead(A0));
    delay(1000);

}
