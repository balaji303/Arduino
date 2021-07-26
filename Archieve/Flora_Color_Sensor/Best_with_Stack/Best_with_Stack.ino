#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
int stackR[5],stackG[5],stackB[5],sumB=0,sumG=0,sumR=0,avgR=0,avgG=0,avgB=0;
float g,b,r;
void setup() {
  Serial.begin(9600);
  Serial.println("Color detection Project");
  Serial.println("Searching Sensor...");
  if (tcs.begin()) {
    Serial.println("Found sensor");
    }
   else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); //halt!   
  }
  tcs.setInterrupt(true);
  for(int i=1;i<6;i++){
  Serial.print(i);
  delay(3000);
  tcs.setInterrupt(false);      // turn on LED ==false *** turn off LED== true 
  delay(60);
  tcs.getRGB(&r, &g, &b);  
  tcs.setInterrupt(true);// change to act like photo flash
  stackR[i]=r;
  stackG[i]=g;
  stackB[i]=b;
  Serial.print("\tR:\t");
  Serial.print(stackR[i]);
  Serial.print("\tG:\t");
  Serial.print(stackG[i]);
  Serial.print("\tB:\t");
  Serial.print(stackB[i]);
  Serial.println("");
}
for(int i=1;i<6;i++){
  sumR=sumR+stackR[i];
  sumG=sumG+stackG[i];
  sumB=sumB+stackB[i];
}
avgR=sumR/5;
avgG=sumG/5;
avgB=sumB/5;
Serial.print("Average of R: ");
Serial.print(avgR);
Serial.print("     ");
Serial.print("Average of G: ");
Serial.print(avgG);
Serial.print("     ");
Serial.print("Average of B: ");
Serial.println(avgB);
Serial.println("**********");
Serial.print("rgb(");
Serial.print(avgR);
Serial.print(",");
Serial.print(avgG);
Serial.print(",");
Serial.print(avgB);
Serial.println(")");
Serial.println("**********");
delay(2000);
Serial.println("The End");
}
void loop() {}
