#include <TCS3200.h>

uint8_t RGBvalue[3];

TCS3200 colSens;

void setup()
{
  Serial.begin(115200);
  Serial.println("BEGIN");
  colSens.begin();
}

void loop()
{
  colSens.loop();
  colSens.getRGB (RGBvalue);
  //colSens.getRGBtoMaxCorrection (RGBvalue);

    Serial.print("C:\t"); Serial.print(1000);
      Serial.print("\tR:\t"); Serial.print(RGBvalue[0]);
      Serial.print("\tG:\t"); Serial.print(RGBvalue[1]);
      Serial.print("\tB:\t"); Serial.print(RGBvalue[2]);
      Serial.print("\t");
      Serial.println();    
}
