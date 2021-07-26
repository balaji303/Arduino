#include "EEPROM.h"
char a[10];
int f;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//EEPROM.get(4);

}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(a);
Serial.println(EEPROM.read(1));
Serial.println(EEPROM.read(4));
delay(1000);
}
