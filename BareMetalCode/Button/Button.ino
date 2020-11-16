int button;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
DDRB &= ~(0x10);//pinmode(12,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(PINB & 0x10){
Serial.println("Button");
}
else{
  Serial.println(" ");
}
}
