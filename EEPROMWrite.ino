#include "EEPROM.h"
int q=303;
char w[10]="BALAJI";
void setup() {
  
  // put your setup code here, to run once:
Serial.begin(9600);
EEPROM.put(4,w);//put any data type
EEPROM.write(1,q);//write only number or int
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(EEPROM.read(4));
Serial.println(EEPROM.read(1));
}
