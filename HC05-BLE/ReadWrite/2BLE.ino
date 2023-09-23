#include <SoftwareSerial.h>
char arrivingdatabyte;
//BLE Module used here is HC05  
SoftwareSerial bt(0,1); //Rx, Tx

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
Serial.print("data byte received:");  
Serial.println(arrivingdatabyte);  
}

}
