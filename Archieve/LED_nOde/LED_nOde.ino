/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////


void setup()
{
  pinMode(14, OUTPUT);
pinMode(12, OUTPUT);

}


void loop()
{

    digitalWrite(14,HIGH);
    delay(1000);
    digitalWrite(12,HIGH);
    delay(1000);
    digitalWrite(14,LOW);
    delay(1000);
    digitalWrite(12,LOW);
    delay(1000);

}
