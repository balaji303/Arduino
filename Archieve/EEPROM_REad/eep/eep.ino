#include "EEPROM.h"
float b;
float f = 0.00f;
int a;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//EEPROM.write(1,30);
//EEPROM.write(2,2.23);
b=EEPROM.get(2,f);
a=EEPROM.read(1);
//b=EEPROM.read(2);
Serial.println(a);
Serial.println(b);
}

void loop() {
  // put your main code here, to run repeatedly:

}
