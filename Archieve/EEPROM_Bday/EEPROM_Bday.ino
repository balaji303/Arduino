#include "EEPROM.h"
#include "ESP8266WiFi.h"
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
EEPROM.write(1,4);
EEPROM.write(2,8);
EEPROM.write(3,19);
EEPROM.write(4,97);
Serial.println("My Birthday date is :");
Serial.print(EEPROM.read(1));
Serial.print("/");
Serial.print(EEPROM.read(2));
Serial.print("/");
Serial.print(EEPROM.read(3));
Serial.print(EEPROM.read(4));
Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}
