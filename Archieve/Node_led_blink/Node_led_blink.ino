/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////

#include <ESP8266WiFi.h>
void setup()
{
  pinMode(1, OUTPUT);
pinMode(3, OUTPUT);

}


void loop()
{

    digitalWrite(1,HIGH);
    delay(1000);
    digitalWrite(3,HIGH);
    delay(1000);
    digitalWrite(3,LOW);
    delay(1000);
    digitalWrite(1,LOW);
    delay(1000);

}
