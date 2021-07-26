#include "abcd.h"
//#include <direct.h>
//int buz=7;
//#define GetCurrentDir _getcwd

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buz,OUTPUT);
//Serial.println(GetCurrentDir());
}


void loop() {
  // put your main code here, to run repeatedly:
tone(buz,100);
delay(1000);
noTone(buz);
delay(2000);
}
