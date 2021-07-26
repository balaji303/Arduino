#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
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
  if((R>90) && (G>80) && (B>34)&&(R<116) && (G<100) && (B<62)){
    Serial.println("Sample 1 High Turbidity"); //Bisleri
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(1,1);
    display.setTextColor(WHITE);
    display.print("S1");
    display.display();  
    delay(1000);
  }
  else if((R>76) && (G>83) && (B>60)&&(R<92) && (G<101) && (B<81)){
  Serial.println("Sample 2"); //Bailley
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(1,1);
  display.setTextColor(WHITE);
  display.print("S2");
  display.display();  
  delay(1000);
  }
  else  if((R>40) && (G>85) && (B>74) && (R<72) && (G<124) && (B<116)){
    Serial.println("Sample 3 Low Turbidity");//Dark Bailley
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(1,1);
  display.setTextColor(WHITE);
  display.print("S3");
  display.display();  
  delay(1000);  
  }
  else  if((R>56) && (G>82) && (B>73) && (R<90) && (G<96) && (B<89)){
    Serial.println("Sample 4 Pure Water");//Schweppes
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(1,1);
  display.setTextColor(WHITE);
  display.print("S4");
  display.display();  
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
  }
  delay(3000);
}
