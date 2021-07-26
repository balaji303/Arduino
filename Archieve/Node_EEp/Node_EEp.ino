#include <EEPROM.h>
void setup()
{
  Serial.begin(9600);
//  delay(1000);
  EEPROM.begin(512);
//  EEPROM.write(0,04);
//  EEPROM.write(1,8);
//  EEPROM.write(2,19);
//  EEPROM.write(3,97);  
  Serial.print((EEPROM.read(0)));
  Serial.print("\\");
  Serial.print((EEPROM.read(1)));
  Serial.print("\\");
  Serial.print((EEPROM.read(2)));
  Serial.print((EEPROM.read(3)));
}
void loop()
{
}
