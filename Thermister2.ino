#include "thermistor.h"

#define NTC_PIN               A0

THERMISTOR thermistor(NTC_PIN,       

                      9000,          

                      3950,           

                      99500);         
uint16_t temp;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  temp = thermistor.read();   
  Serial.print("Temp in 1/10 ºC : ");
  Serial.println(temp);
  delay(5000);
  }
