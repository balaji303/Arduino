/*
  ALKS LED example

  Example with tests of all LEDs and serial communication.

  Example created by Jarek Páral (@JarekParal) @RoboticsBrno
*/

#include <ALKS.h>

void setup() {
    Serial.begin(DEFAULT_SERIAL_SPEED);
    setupRgbLed();
    setupLeds();
}

void loop() {
    Serial.println("RGB-red");
    digitalWrite(L_RGB_R, HIGH);
    delay(500);
    digitalWrite(L_RGB_R, LOW);
    delay(500);
    Serial.println("RGB-green");    
    digitalWrite(L_RGB_G, HIGH);
    delay(500);
    digitalWrite(L_RGB_G, LOW);
    delay(500);
    Serial.println("RGB-blue");    
    digitalWrite(L_RGB_B, HIGH);
    delay(500);
    digitalWrite(L_RGB_B, LOW);
    delay(500);

    Serial.println("led-red");
    digitalWrite(L_R, HIGH);
    delay(500);
    digitalWrite(L_R, LOW);
    delay(500);
    Serial.println("led-yellow");    
    digitalWrite(L_Y, HIGH);
    delay(500);
    digitalWrite(L_Y, LOW);
    delay(500);
    Serial.println("led-green");    
    digitalWrite(L_G, HIGH);
    delay(500);
    digitalWrite(L_G, LOW);
    delay(500);
    Serial.println("led-blue");    
    digitalWrite(L_B, HIGH);
    delay(500);
    digitalWrite(L_B, LOW);
    delay(500);
}
