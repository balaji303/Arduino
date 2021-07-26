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
  int R=0,G=0,B=0;
  tcs.setInterrupt(false); //LED on
  delay(60);   //atleast 50milli Sec for Reading
  tcs.getRGB(&r,&g,&b);
  tcs.setInterrupt(true);  //LED off
  Serial.print("Red: ");
  Serial.print(int(r));
  Serial.print("\t");
  Serial.print("Green: ");
  Serial.print(int(g));
  Serial.print("\t");
  Serial.print("Blue: ");
  Serial.print(int(b));
  Serial.println("\t");
  R=int(r);
  G=int(g);
  B=int(b);
  Serial.print("rgb(");
  Serial.print(R);
  Serial.print(",");
  Serial.print(G);
  Serial.print(",");
  Serial.print(B);
  Serial.println(")");
  Serial.println("***************"); 
  if((R>60) && (G>85) && (B>75)&&(R<70) && (G<100) && (B<90)){
    Serial.println("Low Turbidity");//63,93,81
  }
  else if((R>50) && (G>80) && (B>80)&&(R<60) && (G<105) && (B<90)){
    Serial.println("^^^High Turbidity^^^");//57,95,86
  }
  else{
    Serial.println("Sorry,Error occured");
  }
  Serial.println("***************");
  delay(3000);
}
