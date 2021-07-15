#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define retardo 60
#define escalaejey 10 //en pixels
int i=0,j=0,ii=0,iii=0,muevepantalla=0;
uint8_t arraydatos[129];
uint8_t arrayauxiliar[129];

void setup()   {                  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  display.clearDisplay();
  display.display();
  
  //comment below part to erase the text or put in your own
  display.setCursor(10,22);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(F("Balaji"));
  ////////////////////////////////////////////////////
  
  pinMode(A0,INPUT);

  //initialice data array with all 0
  for(i=0;i<=129;i++)
  {arraydatos[i]=0;}
  for(i=0;i<=129;i++)
  {arrayauxiliar[i]=0;}
}


void loop() {
grid();//SET A FANCY GRID

//THIS FUNCTION DOES THE MAGIC
  for(iii=0;iii<=128;iii++)
  {

if(arraydatos[iii+1]<=arraydatos[iii])//IF OLD DATA IS GREATER THAN NEW DATA STORES 1 IN ARRAYAUXILIAR
{arrayauxiliar[iii]=1;}
if(arraydatos[iii]==0){arrayauxiliar[iii]=0;}//IF NOT MAKE SURE THAT 0 IS STORED IN ARRAYAUXILIAR
if(arraydatos[iii+1]==arraydatos[iii])
{arrayauxiliar[iii]=0;}
arraydatos[iii]=arraydatos[iii+1];//COPY THE DATA ONE POSITION TO THE LEFT
  }


  
arraydatos[127]=map(analogRead(A0),0,1023,0,63);//NEW DATA READ FROM ANALOG PIN STORED AT THE END OF THE ARRAY

plotdata();
  }




  void grid ()//EASY FUNCTION , DRAW A WHITE DOT MULTIPLE TIMES MAKING A GRID
{
for(ii=0;ii<=43;ii++)
{
for(i=0;i<=7;i++)
{
  display.drawPixel(ii*3,escalaejey*i,WHITE);
}

}
      display.display();
}

  





void plotdata()//THIS DOES SOME MAGIC TOO
{
  for(i=0;i<=126;i++)
{  
  if(arrayauxiliar[i]==1){display.drawFastVLine(i,0,63-arraydatos[i],BLACK);}//IF NEW DATA VALUE IS SMALLER THAN OLD DATA VALUE WE NEED TO BUILD THE DATA SECTOR BY SWITCHINGOFF pixels which otherwise would remain ON.
  if(arrayauxiliar[i]==0){display.drawFastVLine(i,63-arraydatos[i],arraydatos[i],WHITE);} //IF NOT JUST SWITCH ON THE PIXELS CREATING A VerticalLine
}
   display.display();

}
