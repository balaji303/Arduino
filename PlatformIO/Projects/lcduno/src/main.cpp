#include <stdio.h>
#include <Arduino.h>
//10-RS
//11-R/W
//12-EN
int i;
uint8_t data_pin[8]={2,3,4,5,6,7,8,9};
/*
data_pin[0] = 2;
data_pin[1] = 3;
data_pin[2] =4;
data_pin[3] =5;
data_pin[4] =6;
data_pin[5] =7;
data_pin[6] =8;
data_pin[7] =9;
*/
void LcdCommand(unsigned char command){
 digitalWrite(10, LOW); //Set zero to RS pin
 digitalWrite(11, LOW); //Set zero to RW pin 
 for (i = 0; i < 8; i++) {
    digitalWrite(data_pin[i], (command >> i) & 0x01);
  }
  digitalWrite(12, LOW);
  delayMicroseconds(1);    
  digitalWrite(12, HIGH);
  delayMicroseconds(1);    // enable pulse must be >450ns
  digitalWrite(12, LOW);
  delayMicroseconds(100);   // commands need > 37us to settle
}

void LcdData(char data){
 digitalWrite(10, HIGH); //Set one to RS pin
 digitalWrite(11, LOW); //Set zero to RW pin 
 for (int i = 0; i < 8; i++) {
    digitalWrite(data_pin[i], (data >> i) & 0x01);
  }
  digitalWrite(12, LOW);
  delayMicroseconds(1);    
  digitalWrite(12, HIGH);
  delayMicroseconds(1);    // enable pulse must be >450ns
  digitalWrite(12, LOW);
  delayMicroseconds(100);   // commands need > 37us to settle
}
void setup() {
  // put your setup code here, to run once:
for(i=2;i<=12;i++){
  pinMode(i,OUTPUT);
}
  delay(30);
	LcdCommand(0x30);
	delay(10);
	LcdCommand(0x30);
	delay(5);
	LcdCommand(0x30);
}

void loop(){
    LcdData('H');
		LcdData('A');
		LcdData('P');
		LcdData('P');
		LcdData('Y');
		LcdData(' ');
		LcdData('D');
		LcdData('E');
		LcdData('E');
		LcdData('P');
		LcdData('A');
		LcdData('V');
		LcdData('A');
		LcdData('L');
		LcdData('I');
		LcdCommand(0xC0);//2ed Line
		LcdData(' ');
		LcdData(' ');
		LcdData('-');
		LcdData('B');
		LcdData('y');
		LcdData(' ');
		LcdData('B');
		LcdData('a');
		LcdData('l');
		LcdData('a');
		LcdData('j');
		LcdData('i');
		LcdData('.');
		LcdData('V');
		delay(10000);
		LcdCommand(1);//Clear screen
		delay(10);
}

/*
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
}
*/

/*
void LiquidCrystal::send(uint8_t value, uint8_t mode) { //mode=Low to write High to read
  digitalWrite(_rs_pin, mode);

  // if there is a RW pin indicated, set it low to Write
  if (_rw_pin != 255) { 
    digitalWrite(_rw_pin, LOW);
  }
  
  if (_displayfunction & LCD_8BITMODE) {
    write8bits(value); 
  } else {
    write4bits(value>>4);
    write4bits(value);
  }
}

void LiquidCrystal::write8bits(uint8_t value) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(_data_pins[i], (value >> i) & 0x01);
  }
  
  pulseEnable();
}

void LiquidCrystal::pulseEnable(void) {
  digitalWrite(_enable_pin, LOW);
  delayMicroseconds(1);    
  digitalWrite(_enable_pin, HIGH);
  delayMicroseconds(1);    // enable pulse must be >450ns
  digitalWrite(_enable_pin, LOW);
  delayMicroseconds(100);   // commands need > 37us to settle
}


inline void LiquidCrystal::command(uint8_t value) {
  send(value, LOW);
}

inline size_t LiquidCrystal::write(uint8_t value) {/////////////
  send(value, HIGH);
  return 1; // assume sucess
}

*/