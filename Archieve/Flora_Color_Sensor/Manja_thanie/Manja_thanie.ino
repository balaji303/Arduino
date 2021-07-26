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
  if((R>90) && (G>80) && (B>34)&&(R<116) && (G<100) && (B<62)){
    Serial.println("Sample 1 High Turbidity"); //Bisleri
  }
  else if((R>76) && (G>83) && (B>60)&&(R<92) && (G<101) && (B<81)){
    Serial.println("Sample 2"); //Bailley
  }
  else  if((R>40) && (G>85) && (B>74) && (R<72) && (G<124) && (B<116)){
    Serial.println("Sample 3 Low Turbidity");//Dark Bailley
  }
    else  if((R>56) && (G>82) && (B>73) && (R<90) && (G<96) && (B<89)){
    Serial.println("Sample 4 Pure Water");//Schweppes
  }
  else{
    Serial.println("Sorry,Error occured");
    
  }
  Serial.println("***************");
  delay(3000);
}
