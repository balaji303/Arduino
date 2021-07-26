//03- Slave 1
//address 10
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
Wire.begin(10);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
Wire.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void receiveEvent(){
  while(Wire.available()){
      char s=Wire.read();
      if(s=='H'){
        digitalWrite(13,HIGH);
      }
      else if(s=='L'){
        digitalWrite(13,LOW);
      }
      else{
        //Do nothing
      }
  }
}
