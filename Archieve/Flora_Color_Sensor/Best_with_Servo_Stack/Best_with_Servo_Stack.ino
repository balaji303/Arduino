#include <Servo.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
int stackR[5],stackG[5],stackB[5],sumB=0,sumG=0,sumR=0,avgR=0,avgG=0,avgB=0;
float g,b,r;
Servo myservo;
void setup(void) {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9);
  Serial.println("Color detection Project");
  delay(200);
  Serial.println("Searching Sensor...");
  if (tcs.begin()) {
    Serial.println("Color Sensor Found");
    }
   else {
    Serial.print("Buffering");
    delay(1000);
    Serial.println("..");
    Serial.println("Check your wire");
    while(1){
      Serial.println("Try again");
      delay(5000);
    } //halt!   
  }
}

void loop(void) {
  // put your main code here, to run repeatedly:
  int sumB=0,sumG=0,sumR=0,avgR=0,avgG=0,avgB=0,R=0,G=0,B=0;
  tcs.setInterrupt(true);
  for(int i=1;i<6;i++){
  Serial.print(i);
  delay(2000);
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
R=avgR;
G=avgG;
B=avgB;
Serial.println("**********");
Serial.print("rgb(");
Serial.print(R);
Serial.print(",");
Serial.print(G);
Serial.print(",");
Serial.print(B);
Serial.println(")");
Serial.println("**********");
  if((R>170) && (G>20) && (B>20)&&(R<240) && (G<55) && (B<55)){
    Serial.println("Red");
    myservo.write(180);
    delay(1000);
  }
  else if((R>20) && (G>50) && (B>120)&&(R<50) && (G<90) && (B<190)){
    Serial.println("Blue");
    myservo.write(135);
    delay(1000);
  }
  else  if((R>110) && (G>70) && (B>20) && (R<130) && (G<100) && (B<50)){
    Serial.println("Yellow");
    myservo.write(20);
    delay(1000);
  }
   else  if((R>50) && (G>120) && (B>40) && (R<70) && (G<155) && (B<70)){
    Serial.println("Green");
    myservo.write(55);
    delay(1000);
  }
  else{
    Serial.println("Sorry,Error occured");
    myservo.write(10);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(10);
    delay(1000);
  }
  delay(3000);
}
