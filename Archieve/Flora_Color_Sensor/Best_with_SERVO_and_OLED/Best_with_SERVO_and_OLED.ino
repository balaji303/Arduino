//Voltage problem between servo and OLED
#include <Wire.h>
#include <Servo.h>
#include "Adafruit_TCS34725.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);
Servo myservo;
void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  myservo.attach(9);
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
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(25,1);
  display.setTextColor(BLACK, WHITE);
  display.print("Green");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("vironment");
  display.setTextSize(3);
  display.setCursor(59,20);
  display.print("->");
  display.setCursor(29,30);
  display.print("<-");
  display.setTextSize(1);
  display.setCursor(1,56);
  display.setTextColor(BLACK, WHITE);
  display.print("Clean");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("earth,");
  display.setTextColor(BLACK, WHITE);
  display.print("Safe");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("life");
  display.display();
}
void loop(void) {
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
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(35,24);
  display.setTextColor(WHITE);
  display.print("RED");
  display.display();
  myservo.write(165);  
  delay(1000);
  }
  else if((R>20) && (G>50) && (B>120)&&(R<50) && (G<90) && (B<190)){
    Serial.println("Blue");
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(35,24);
  display.setTextColor(WHITE);
  display.print("BLUE");
  display.display();
  myservo.write(125);  
  delay(1000);
  }
  else  if((R>110) && (G>70) && (B>20) && (R<130) && (G<100) && (B<50)){
    Serial.println("Yellow");
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(35,24);
  display.setTextColor(WHITE);
  display.print("YELLOW");
  display.display(); 
  myservo.write(10); 
  delay(1000);
  }
   else  if((R>50) && (G>120) && (B>40) && (R<70) && (G<155) && (B<70)){
    Serial.println("Green");
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(35,24);
  display.setTextColor(WHITE);
  display.print("GREEN");
  display.display();
  myservo.write(45);  
  delay(1000);
  }
  else{
  Serial.println("Sorry,Error occured");
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(25,1);
  display.setTextColor(BLACK, WHITE);
  display.print("Green");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("vironment");
  display.setTextSize(3);
  display.setCursor(59,20);
  display.print("->");
  display.setCursor(29,30);
  display.print("<-");
  display.setTextSize(1);
  display.setCursor(1,56);
  display.setTextColor(BLACK, WHITE);
  display.print("Clean");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("earth,");
  display.setTextColor(BLACK, WHITE);
  display.print("Safe");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("life");
  display.display();
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
