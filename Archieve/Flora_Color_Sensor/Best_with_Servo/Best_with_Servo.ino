#include <Servo.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);
Servo myservo;
void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
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
  if((R>170) && (G>20) && (B>20)&&(R<240) && (G<55) && (B<59)){
    Serial.println("Red");
    myservo.write(165);
    delay(1000);
  }
  else if((R>20) && (G>50) && (B>120)&&(R<50) && (G<90) && (B<190)){
    Serial.println("Blue");
    myservo.write(125);
    delay(1000);
  }
  else  if((R>110) && (G>70) && (B>20) && (R<130) && (G<100) && (B<50)){
    Serial.println("Yellow");
    myservo.write(10);
    delay(1000);
  }
   else  if((R>50) && (G>120) && (B>40) && (R<70) && (G<155) && (B<70)){
    Serial.println("Green");
    myservo.write(45);
    delay(1000);
  }
  else{
    Serial.println("Sorry,Error occured");
    myservo.write(20);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(150);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(20);
    delay(1000);
  }
  delay(3000);
}
