#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);
void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  Serial.println("Color detection Project");
  delay(200);
  Serial.println("Searching Sensor...");
  delay(100);
  if(tcs.begin()){
    Serial.println("Color Sensor Found");
  }
  else{
    Serial.print("Buffering");
    delay(1000);
    Serial.println("..");
    Serial.println("Check your wire");
    while(1){
      Serial.println("Try again");
      delay(5000);
    }
  }
}
void loop(void) {
  // put your main code here, to run repeatedly:
  float r,g,b;
  tcs.setInterrupt(false); //LED on
  delay(60);   //atleast 50milli Sec for Reading
  tcs.getRGB(&r,&g,&b);
  tcs.setInterrupt(true);  //LED off
  Serial.print("R: ");
  Serial.print(int(r));
  Serial.print("\t");
  Serial.print("G: ");
  Serial.print(int(g));
  Serial.print("\t");
  Serial.print("B: ");
  Serial.print(int(b));
  Serial.println("\t");
  Serial.print("rgb(");
  Serial.print(int(r));
  Serial.print(",");
  Serial.print(int(g));
  Serial.print(",");
  Serial.print(int(b));
  Serial.println(")");
  delay(4000);
}
