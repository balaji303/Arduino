//01-Master code
#include <Wire.h>
void setup() {
Wire.begin(); //Master dont neeed address
Serial.begin(9600);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
}

void loop() {
while(Serial.available()){
  char s=Serial.read();
  if(s =='H'){
    Serial.println("High");
    digitalWrite(13,LOW);
    Wire.beginTransmission(5); //Address of Slave
    Wire.write('H');
    Wire.endTransmission(5);
  }
  else if(s =='L'){
    digitalWrite(13,LOW);
    Serial.println("Low");
    Wire.beginTransmission(5); //Address of Slave
    Wire.write('L');
    Wire.endTransmission(5);
  }
  else{
    Serial.println("Invalid");
    digitalWrite(13,HIGH);
    Wire.beginTransmission(5); //Address of Slave
    Wire.write('L');
    Wire.endTransmission(5);
    delay(1000);
  }
}
}
