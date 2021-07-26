/*
  ALKS LED controlled example

  Example with LED controlled by button.

  Example created by Jarek Páral (@JarekParal) @RoboticsBrno
*/

#include <ALKS.h>
void setup() {
    Serial.begin(DEFAULT_SERIAL_SPEED);
    setupRgbLed();
    setupLeds();
    setupButtons();
}

void loop() {
    if(digitalRead(SW1) == true) {
        digitalWrite(L_R, LOW);
        Serial.println("SW1 not press => no light");
    } else {
        digitalWrite(L_R, HIGH);
        Serial.println("SW1 is press => RED light");
    }
    delay(200);
}
