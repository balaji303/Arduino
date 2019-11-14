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
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  high(10);
  low(10);
  high(5);
  low(5);
}
