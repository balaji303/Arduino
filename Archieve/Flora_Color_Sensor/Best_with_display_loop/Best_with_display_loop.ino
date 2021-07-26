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
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(25,1);
  display.setTextColor(BLACK, WHITE);
  display.print("Green");
  display.setTextColor(WHITE);
  display.print("");
  display.print("vironment");
  display.setTextSize(3);
  display.setCursor(59,20);
  display.print("->");
  display.setCursor(29,30);
  display.print("<-");
  display.setTextSize(1);
  display.setCursor(1,56);
  display.setTextColor(BLACK, WHITE);
  display.print(" Clean");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("earth,");
  display.setTextColor(BLACK, WHITE);
  display.print("Safe");
  display.setTextColor(WHITE);
  display.print("");
  display.print("life");
  display.display();
  delay(2000);
  int R=0,G=0,B=0;
  float r=0,g=0,b=0;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1,1);  //49 colum, 1 row
  tcs.setInterrupt(true);
  tcs.setInterrupt(false);      // turn on LED ==false *** turn off LED== true 
  delay(60);
  tcs.getRGB(&r, &g, &b);  
  tcs.setInterrupt(true);// change to act like photo flash
  Serial.print("\tR:\t");
  Serial.print(int(r));
  Serial.print("\tG:\t");
  Serial.print(int(g));
  Serial.print("\tB:\t");
  Serial.print(int(b));
  Serial.println("");
R=int(r);
G=int(g);
B=int(b);
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
display.setTextSize(7);
display.print("Red");
    }
  else if((R>20) && (G>50) && (B>120)&&(R<50) && (G<90) && (B<190)){
//  Serial.println("Blue");
//void greenfun(void);
  display.setTextSize(5);
  display.print("Blue");
  }
  else  if((R>110) && (G>70) && (B>20) && (R<130) && (G<100) && (B<50)){
//    Serial.println("Yellow");
//  void  greenfun(void);  //49 colum, 1 row
  display.setTextSize(3);
  display.print("Yellow");
    }
   else  if((R>50) && (G>120) && (B>40) && (R<70) && (G<155) && (B<70)){
//  Serial.println("Green");
//  void greenfun(void);
  display.setTextSize(4);
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
  delay(3000);
}
