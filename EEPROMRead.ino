#include "EEPROM.h"
int a=511;
int value;

void fun(){ //function 
value=EEPROM.read(a);
Serial.print(a);
Serial.print(":");
Serial.println(value);
delay(300);
}
void setup() {
Serial.begin(9600);
}

void loop() {
for(;a>0;--a){
  fun();
}
}
