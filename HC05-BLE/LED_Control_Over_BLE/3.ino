#include <SoftwareSerial.h>
int arrivingdatabyte;  
//BLE Module used here is HC05  
SoftwareSerial bt(2,3); //Rx, Tx

void setup() {
  // put your setup code here, to run once:
bt.begin(9600);
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if (bt.available())
{
  arrivingdatabyte = bt.read();  // It will read the incoming or arriving data byte  
// Serial.print("data byte received:");  
Serial.println(arrivingdatabyte);  
if(arrivingdatabyte == '1')
{
  digitalWrite(13,HIGH);
  delay(1000);
}
else if (arrivingdatabyte == '2')
{
  digitalWrite(13,LOW);
  delay(1000);
}
else
{
  //do nothing
}
}

}
