#include <Wire.h>

#define SLAVE_ADDR 0x8
#define MAX_INDEX  4
// Global variables
char databyte[MAX_INDEX]={'0','1','1','0'};  
int index = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(Data_Req_Event);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(13, HIGH);
  // delay(1000);
  // digitalWrite(13, LOW);
  delay(1000);
}

void Data_Req_Event(void)
{
  if(databyte[index] == '1')
  {
    digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13, LOW);
    delay(10);
  }
  Wire.write(&databyte[index],1);
  if(index > (MAX_INDEX-2))
  {
    index = 0;
  }
  else
  {
    index++;
  }
  
}
