//not working
#include <CayenneMQTTESP8266.h>//IMPPORT LIBRARY FROM http://easycoding.tn/index.php/resources/

char Cayenneusername[] = "b18b9a10-c24c-11e9-80af-177b80d8d7b2";
char Cayennepassword[] = "cd39be81413d4008ee311397c1ac28849b26c6e0";
char CayenneclientID[] = "d93dcd80-c24c-11e9-809b-df5a1171d82f";
#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  Cayenne.begin(Cayenneusername, Cayennepassword, CayenneclientID);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("ChaosFather","BALAJIbalaji");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("Buffer");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));

}


void loop()
{

    Cayenne.virtualWrite(1,(random(0,100)));
    delay(1000);

}
