#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
void setup() {
  Serial.begin(9600);
  Serial.println("Color View Test!");
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
}
void loop() {
  uint16_t clear, red, green, blue;
  tcs.setInterrupt(false);      // turn on LED
  delay(3000);  // takes 50ms to read 
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);  // turn off LED
  Serial.print("C:"); Serial.print(clear);
  Serial.print("\tR:"); Serial.print(red);
  Serial.print("\tG:"); Serial.print(green);
  Serial.print("\tB:"); Serial.println(blue);
}
