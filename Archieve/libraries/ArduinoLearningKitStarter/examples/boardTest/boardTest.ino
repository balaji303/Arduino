/*
  ArduinoLearningKitStarter (ALKS) Board tester firmware

  This example is used for testing ALKS boards after manufacturing process.

  Original example created by Jakub Streit (@cednik) and Jarek Páral (@JarekParal) @RoboticsBrno
  Rework done by Kryštof Černý (@CornyjK) @RoboticsBrno
*/

#include <ALKS.h>
#include <DHT.h>

#define DHTTYPE  DHT11

DHT dht(DHT_PIN, DHTTYPE);

unsigned long t_inc = 0;
unsigned long t_meas = 0;
uint8_t cnt = 0;

void setup() {
  setupAll();
  Serial.begin(DEFAULT_SERIAL_SPEED);
  dht.begin();
  Serial.println("ALKS hardware test firmware");
}

void loop() {
  if ((millis() - t_inc) >= 500)
  {
    t_inc = millis();
    ++cnt;
    digitalWrite(L_R, cnt & 1 ? HIGH : LOW);
    digitalWrite(L_Y, cnt & 2 ? HIGH : LOW);
    digitalWrite(L_G, cnt & 4 ? HIGH : LOW);
    digitalWrite(L_B, cnt & 8 ? HIGH : LOW);
  }

  if ((millis() - t_meas) >= 500)
  {
    t_meas = millis();
    float t = dht.readTemperature();
    if (isnan(t))
    {
      Serial.println("TEMPERATURE ERROR");
    }
    else
    {
      Serial.print("Temperature: ");
      Serial.print(int(t));
    }
    Serial.print("\tlight: ");
    Serial.print(analogRead(PHOTO));
    Serial.print("\tleft pot: ");
    Serial.print(analogRead(POT1));
    Serial.print("\tright pot: ");
    Serial.print(analogRead(POT2));
    Serial.print("\n");
  }

  digitalWrite(L_RGB_R, digitalRead(SW3) == HIGH ? LOW : HIGH);
  digitalWrite(L_RGB_G, digitalRead(SW2) == HIGH ? LOW : HIGH);
  digitalWrite(L_RGB_B, digitalRead(SW1) == HIGH ? LOW : HIGH);

  if (Serial.available())
  {
    char c = Serial.read();
    switch (c)
    {
      case '\r':
        Serial.write('\n');
        break;
      default:
        Serial.write(c + 1);
        Serial.write('\n');
        break;
    }
  }
}
