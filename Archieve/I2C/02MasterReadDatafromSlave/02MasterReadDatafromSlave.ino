//02-MAster code
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 char a=5;
// if(Serial.available()>0){
//  a=Serial.read();
// }
 Wire.begin(10);
 pinMode(13,OUTPUT);
 digitalWrite(13,HIGH);
 delay(1000);
 digitalWrite(13,LOW);
 Wire.requestFrom(10,a);   
 while(Wire.available()){
  char c=Wire.read();
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  Serial.println(c);
  Serial.flush();
  Wire.flush();
 }
}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
}
