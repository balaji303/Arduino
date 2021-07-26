#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
void setup(void) {
  Serial.begin(9600);
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.print("Welcome");
  display.display();
  delay(5000);
  display.clearDisplay();
  Serial.println("Color detection Project");
  if (tcs.begin()) {
  Serial.println("Searching Sensor...");
    }
   else {    Serial.print("Buffering");
    delay(1000);
    Serial.println("..");
    Serial.println("Check your wire");
    while(1){
      Serial.println("Try again");
      delay(5000);
    }   
  }
  
  // display a pixel in each corner of the screen
}
void loop() {
  int stackR[5],stackG[5],stackB[5];
  int sumB=0,sumG=0,sumR=0;
  int avgR=0,avgG=0,avgB=0;
  int R=0,G=0,B=0;
  // put your main code here, to run repeatedly:
  float r,g,b;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1,1);  //49 colum, 1 row
  
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
delay(2000);
display.clearDisplay();
if((R>170) && (G>20) && (B>20)&&(R<240) && (G<55) && (B<55)){
//  Serial.println("Red");
display.print("Red");
    }
  else if((R>20) && (G>50) && (B>120)&&(R<50) && (G<90) && (B<190)){
//  Serial.println("Blue");
//void greenfun(void);
  display.print("Blue");
  }
  else  if((R>110) && (G>70) && (B>20) && (R<130) && (G<100) && (B<50)){
//    Serial.println("Yellow");
//  void  greenfun(void);  //49 colum, 1 row
  display.print("Yellow");
    }
   else  if((R>50) && (G>120) && (B>40) && (R<70) && (G<155) && (B<70)){
//  Serial.println("Green");
//  void greenfun(void);
  display.print("Green");
   }
  else{
    display.clearDisplay();
    for(int i=0;i<120;i=i+20){
    for(int j=0;j<64;j=j+25){
    display.setCursor(i,j);
     display.setTextSize(4);
     display.print("X"); //@,#,X
     display.display();    
    }
  }
  }
  display.display();
  delay(5000);
}
