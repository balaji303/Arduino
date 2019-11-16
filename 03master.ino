#include <Wire.h>
void high(int add)
{
  Wire.beginTransmission(add);
  Wire.write('H');
  Wire.endTransmission();
delay(1000);
}
void low(int add)
{
  Wire.beginTransmission(add);
  Wire.write('L');
  Wire.endTransmission();
delay(1000);
}
void setup() {
Serial.begin(9600);
Wire.begin();
}

void loop() {
  high(10);
  low(10);
  high(5);
  low(5);
}
