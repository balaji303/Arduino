#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
void setup(void) {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
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
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1,1);  //49 colum, 1 row
  display.print("rgb(");
  display.print(int(r));
  display.print(",");
  display.print(int(g));
  display.print(",");
  display.print(int(b));
  display.println(")");
  display.display();
  delay(4000);
}
