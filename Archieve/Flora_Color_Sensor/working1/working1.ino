//https://github.com/adafruit/Adafruit_TCS34725/tree/master/examples/colorview
//got from  github Gives HTML format itself
#include <Wire.h>
#include "Adafruit_TCS34725.h"
byte gammatable[256];
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
void setup(void) {
  Serial.begin(9600);
  Serial.println("Color View Test!");
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
  // thanks PhilB for this gamma table!
  // it helps convert RGB colors to what humans see
//  for (int i=0; i<256; i++) {
//    float x = i;
//    x /= 255;
//    x = pow(x, 2.5);
//    x *= 255;
//    if (commonAnode) {
//      gammatable[i] = 255 - x;
//    } else {
//      gammatable[i] = x;
//    }
//    //Serial.println(gammatable[i]);
//  }
}
// The commented out code in loop is example of getRawData with clear value.
// Processing example colorview.pde can work with this kind of data too, but It requires manual conversion to 
// [0-255] RGB value. You can still uncomments parts of colorview.pde and play with clear value.
void loop(void) {
  float red, green, blue;
  tcs.setInterrupt(false);  // turn on LED
  delay(60);  // takes 50ms to read
  tcs.getRGB(&red, &green, &blue);
  tcs.setInterrupt(true);  // turn off LED
  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
//  Serial.print("\t");
//  Serial.print((int)red, HEX); Serial.print((int)green, HEX); Serial.print((int)blue, HEX);
  Serial.print("\n");
//  uint16_t red, green, blue, clear;
//  
//  tcs.setInterrupt(false);  // turn on LED
//
//  delay(60);  // takes 50ms to read
//
//  tcs.getRawData(&red, &green, &blue, &clear);
//  
//  tcs.setInterrupt(true);  // turn off LED
//
//  Serial.print("C:\t"); Serial.print(int(clear)); 
//  Serial.print("R:\t"); Serial.print(int(red)); 
//  Serial.print("\tG:\t"); Serial.print(int(green)); 
//  Serial.print("\tB:\t"); Serial.print(int(blue));
//  Serial.println();
}
