# include <SPI.h>
#define MAX_INDEX 4
// char str[ ]="Hello Slave, I'm Arduino MEGA\n";
char str[MAX_INDEX]={'0','1','1','0'};
int indexVal = 0;
void setup() 
{
Serial.begin(115200); // set baud rate to 115200 for usart
SPI.begin();
SPI.setClockDivider(SPI_CLOCK_DIV8); //divide the clock by 8
Serial.println("Hello I'm SPI Mega_Master");
} 

void loop (void)
{
  digitalWrite(SS, LOW); // enable Slave Select
  // send test string
  // for(int i=0; i< 4; i++)
  // { 
  SPI.transfer( str[indexVal] );
  Serial.println(str[indexVal]);
  // }
  digitalWrite(SS, HIGH); // disable Slave Select
  delay(2000);
  if( indexVal > (MAX_INDEX-2) )
  {
    indexVal = 0;
  }
  else
  {
    indexVal++;
  }
}