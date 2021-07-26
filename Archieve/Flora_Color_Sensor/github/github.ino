//https://github.com/GaboLC/Flora-Color-Sensor-Example/blob/master/Flora_Color_Sensor_Example/Flora_Color_Sensor_Example.ino
// Got from github
#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X); // 101MS
void setup(void) {
  Serial.begin(9600);
  tcs.begin(); // inicializamos el sensor 
  tcs.setInterrupt(true); // Empezamos apagando el led 
}
void loop(void) {
  uint16_t clear, red, green, blue, colorTemp, lux; // Variables de recoleccion de datos 
  tcs.setInterrupt(false);      // prende el LED 
  delay(60);  // Toma 60 ms para leer
  tcs.getRawData(&red, &green, &blue, &clear); //recolecta los Rawdata 
  tcs.setInterrupt(true);  // Apaga el LED 
  // Conversion de valores RGB raw a RGB estandar 
  uint32_t sum = clear;
  float rojo, verde, azul;
  rojo = red; rojo /= sum;
  verde = green; verde /= sum;
  azul = blue; azul /= sum;
  rojo *= 256; verde *= 256; azul *= 256;
  colorTemp = tcs.calculateColorTemperature(rojo, verde, azul); // calcula la temperatura del color \\
  lux = tcs.calculateLux(rojo, verde, azul); // calcula la luminosidad \\
  Serial.println(" ");
  Serial.println("----------------------------------------");
  Serial.println(" ");
  Serial.print("Valores RGB crudos: "); Serial.print("C: "); Serial.print(clear);
  Serial.print(" - R:"); Serial.print(red);
  Serial.print(" - G: "); Serial.print(green);
  Serial.print(" - B: "); Serial.print(blue);
  Serial.println(" ");
  Serial.println(" ");
  Serial.print("Valor Hexadecimal: "); Serial.print((int)rojo, HEX); Serial.print((int)verde, HEX); Serial.print((int)azul, HEX);
  Serial.println(" ");
  Serial.println(" ");
  Serial.print("Valores RGB convertidos: "); Serial.print((int)rojo); Serial.print(" "); Serial.print((int)verde); Serial.print(" "); Serial.print((int)azul);
  Serial.println(" ");
  Serial.println(" ");
  Serial.print("Temperatura del color: "); Serial.print(colorTemp, DEC);
  Serial.println(" ");
  Serial.println(" ");
  Serial.print("Lux: "); Serial.print(lux, DEC);
  Serial.println(" ");
  Serial.println(" ");
  delay(5000);
}
