/*  RGB light sensor demo sketch

 * 

 * This sketch gets a color RGB reading from the light sensor 

 * on the Adafruit TCS34725 (or equivelant) breakout module.

 * 

 * This sketch was adapted from the original that comes with the 

 * Adafruit library for Arduino Step by Step by Peter Dalmaris.

 * 

 * Components

 * ----------

 *  - Arduino Uno

 *  - Adafruit RGB TCS34725 sensor breakout or equivelant

 *  

 *  Libraries

 *  ---------

 *  - Wire

 *  - Adafruit_TCS34725

 *

 * Connections

 * -----------

 *  Break out    |    Arduino Uno

 *  -----------------------------

 *      VIN      |      5V

 *      GND      |      GND

 *      SCL      |      SCL or A5

 *      SDA      |      SDA or A4

 *      LED      |      GND to turn off (or any digital out set to LOW)

 *      INT      |      2 (but not used in this sketch)

 * 

 * Other information

 * -----------------

 *  For information on RGB color: https://en.wikipedia.org/wiki/RGB_color_model

 *  For information on color temperature: https://en.wikipedia.org/wiki/Color_temperature

 *  For more information on the breakout see https://www.adafruit.com/product/1334

 *  The repository for the library used is at https://github.com/adafruit/Adafruit_TCS34725

 *  

 *  Created on October 8 2016 by Peter Dalmaris

 * 

 */
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
  tcs.setInterrupt(true);      // turn on LED
  delay(3000);  // takes 50ms to read 
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);  // turn off LED
  Serial.print("C:"); Serial.print(clear);
  Serial.print("\tR:"); Serial.print(red);
  Serial.print("\tG:"); Serial.print(green);
  Serial.print("\tB:"); Serial.println(blue);
  if (red>green && green==blue && red>blue){
    Serial.println("Red");
  }
  else if (green==red && green>blue && red>blue){
    Serial.println("Green");
  }
  else if (red>23 && red>green && green>blue && red>blue){
    Serial.println("Yellow");
  }
  else if ( red>green && blue>green && red>blue){
    Serial.println("Blue");
  }
  else if (red>23 && red>green && blue>green && red>blue){
    Serial.println("Violet");
  }
  else if ( blue>15 && red>green && blue==green && red>blue){
    Serial.println("Sky blue");
  }
  else {Serial.println("Sound of the Police");}
}
