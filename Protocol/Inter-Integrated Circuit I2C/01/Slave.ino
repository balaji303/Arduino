//01-Slave code
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
Wire.begin(5);       //Slave address
Serial.begin(9600);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
delay(1000);
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
Wire.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void receiveEvent(){
  while(Wire.available()){
    char c=Wire.read();
    if(c =='H'){
      digitalWrite(13,HIGH);
    }
    else if(c =='L'){
      digitalWrite(13,LOW);
    }
  }
}
