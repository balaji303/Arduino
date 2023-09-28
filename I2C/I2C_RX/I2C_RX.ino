#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  pinMode(13,OUTPUT);
}

void loop() {
  char readByte;
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8,1);

  if(Wire.available())
  {
    readByte = Wire.read();
    Serial.write(readByte);
  }
  delay(1000);
    // If 1 is sent, glow the LED in Tx-Board
  if (readByte == '1')
  {
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }
}
