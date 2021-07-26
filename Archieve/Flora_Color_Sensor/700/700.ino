#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_60X);
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
  uint16_t clear, red, green, blue,Avg;
  tcs.setInterrupt(true);      // turn on LED ==false *** turn off LED== true
  delay(5000);  // takes 500ms to read 
  tcs.getRawData(&red, &green, &blue, &clear);
  delay(500);  
  tcs.setInterrupt(false);  // change to act like photo flash
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.println(blue);
}
