#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
void setup() {
  // initialize and clear display
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  
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
  
  display.clearDisplay();
  display.setTextSize(7);
  display.setTextColor(WHITE);
  display.setCursor(1,1);  //49 colum, 1 row
  display.print("Red");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(1,1);  //49 colum, 1 row
  display.print("Yellow");
  display.display();
  delay(2000);
  
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(1,1);  //49 colum, 1 row
  display.print("Green");
  display.display();
  delay(2000);
  
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(1,1);  //49 colum, 1 row
  display.print("Blue");
  display.display();
  display.clearDisplay();
  delay(2000);

  display.setCursor(1,1);
  for(int i=0;i<120;i=i+20){
    for(int j=0;j<64;j=j+25){
    display.setCursor(i,j);
     display.setTextSize(4);
     display.print("X"); //@,#,X
     display.display();    
    }
  }
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
}
