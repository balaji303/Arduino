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
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  display.clearDisplay();
  // display a pixel in each corner of the screen


  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(49,1);  //49 colum, 1 row
  display.print("Hello, world!");
  display.setTextSize(2);
  display.setCursor(1,30);
  display.setTextColor(BLACK, WHITE); // Draw 'inverse' text
  display.print(" V.");
  display.setTextColor(WHITE);
  display.print(" ");
  display.print("Balaji");
  display.display();  
}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
    for( uint8_t i=0;i<63;i++){
    display.drawPixel(5, i, WHITE);
    }
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);
display.display();
}
