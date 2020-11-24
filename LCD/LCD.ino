  uint8_t resetpin=12;
  uint8_t rwpin=0; //LOW: Write and HIGH: Read
  uint8_t enablepin=11;
  uint8_t datapins[4]={5,4,3,2};
  uint8_t lcdfunction=0x04;
  uint8_t lcdcontrol;
  uint8_t lcdmode;

void begin(void){
  lcdfunction=0x04;
  pinMode(resetpin, OUTPUT);
  pinMode(enablepin, OUTPUT);
  for (int i=0; i<4; ++i)
  {
    pinMode(datapins[i], OUTPUT);
   } 
  delayMicroseconds(50000); 
  digitalWrite(resetpin, LOW);
  digitalWrite(enablepin, LOW);
}
void pulse(void) {
  digitalWrite(enablepin, LOW);
  delayMicroseconds(1);    
  digitalWrite(enablepin, HIGH);
  delayMicroseconds(1);    // enable pulse must be >450ns
  digitalWrite(enablepin, LOW);
  delayMicroseconds(100);   // commands need > 37us to settle
}

void lcdwrite(uint8_t value){
  for(int i=0;i<4;i++){
    digitalWrite(datapins[i],(value>>i)&0x01);
  }
  pulse();
}

void send(uint8_t value, uint8_t mode) {
  digitalWrite(resetpin, mode);
  // if there is a RW pin indicated, set it low to Write
    lcdwrite(value>>4);
    lcdwrite(value);
}

void command(uint8_t value) { //Send only control command for LCD
  send(value, LOW);
}

int write(uint8_t value) { //Sends data to LCD
  send(value, HIGH);
  return 1; 
}

void setup() {
  begin();
  //Initializing LCD display
  lcdwrite(0x03);
  delayMicroseconds(4500); 
  lcdwrite(0x03);
  delayMicroseconds(4500); 
  lcdwrite(0x03); 
  delayMicroseconds(150);
  //set to 4bit interface
  lcdwrite(0x02); 
  //Set 1line and function set at 0x20(Medium Contrast)
  command(0x20 | lcdfunction);  
  //Turn ON display with no cursor
  lcdcontrol = 0x04;
  command(0x08 | lcdcontrol);
  // clear display, set cursor position to zero
  command(0x01);  
  delayMicroseconds(2000);  
  //Set on Entry mode
  lcdmode = 0x02 | 0x00;
  command(0x04 | lcdmode);
  //Writing data
  write('H');
  write('A');
  write('P');
  write('P');
  write('Y');
  write(' ');
  write('B');
  write('I');
  write('R');
  write('T');
  write('H');
  write('D');
  write('A');
  write('Y');
}

void loop() {
  delay(100);//Do nothing
}
