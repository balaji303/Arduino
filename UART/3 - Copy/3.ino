#include <SoftwareSerial.h>
String databyte;  
SoftwareSerial UNO(0,1);
void setup() {
  // put your setup code here, to run once:
UNO.begin(9600);
// pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// if (UNO.available())
// {
  // digitalWrite(13,LOW);
  databyte = UNO.readString();
  if (strlen((const char*)&databyte) > 1)
  {
    UNO.print("UNO receieved:");
    UNO.println(databyte);
    delay(1000); 
  }
// }
// else
// {
//   digitalWrite(13,HIGH);
// }
}
// // 
//Receiver Arduino Board Code
// char mystring[20];               //Initialized variable to store receive
// void setup() {
//  Serial.begin(9600);             // Begin the Serial at 9600 Baud
// }
// void loop() {
//  Serial.readBytes(mystring,15);  //Read the serial data
//  Serial.println(mystring);       //Print data on Serial Monitor
//  Serial.println(" RECEIVER");
//  delay(1000);    
// }