#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Debug.h>
#include <MFRC522Extended.h>
#include <MFRC522Hack.h>
#include <require_cpp11.h>
#include<RFID.h>
#include <SPI.h>
#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

Servo myservo; // create servo object to control a servo
// twelve servo objects can be created on most boards
#define val0 117 // chnage the value according to token no
#define val1 134
int pos = 0;
/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 10
#define RESET_DIO 9
RFID RC522(SDA_DIO, RESET_DIO);

void setup()
{ 
myservo.attach(8); 
Serial.begin(9600);
/* Enable the SPI interface */
SPI.begin(); 
/* Initialise the RFID reader */
RC522.init();
lcd.begin(16, 2);

}

void loop()
{
byte i=0;
int ID;
if (RC522.isCard())
{
RC522.readCardSerial();
Serial.println(RC522.serNum[i],DEC);
Serial.println("Card detected:");
ID=RC522.serNum[0];}
delay(500);
if( val0 == ID)
{ lcd.clear();
lcd.print("Access Granted");
lcd.setCursor(0, 1);
lcd.print("Welcome Haris");
delay(1800); 
lcd.clear();
lcd.print("Door Opening");
delay(1500);
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
// in steps of 1 degree
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(15); // waits 15ms for the servo to reach the position
}
delay(5000);
lcd.clear();
lcd.print("Door Closing");
delay(1500);
for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(15); // waits 15ms for the servo to reach the position
}
} 
else
{
lcd.clear();
lcd.print("Door Security ");
lcd.setCursor(0, 1);
lcd.print("System ");
}
if( val1 == ID)
{ lcd.clear();
lcd.print("Access Granted");
lcd.setCursor(0, 1);
lcd.print("Welcome Bilal");
delay(1800); 
lcd.clear();
lcd.print("Door Opening");
delay(1500);
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
// in steps of 1 degree
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(15); // waits 15ms for the servo to reach the position
}
delay(5000);
lcd.clear();
lcd.print("Door Closing");
delay(1500);
for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(15); // waits 15ms for the servo to reach the position
}
} 
else
{
lcd.clear();
lcd.print("Door Security ");
lcd.setCursor(0, 1);
lcd.print("System ");
}
}
