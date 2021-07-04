/**
 * PIN 13- Digital Read
 * 
 * 
 * PIN 10- Digital Read-Print 10
 * 
 * Both
 */
 #include <STM32F1xx.h>
 uint8_t buttonState13,buttonState10;
void setup() {
  // put your setup code here, to run once:
pinMode(13,INPUT);
pinMode(10,INPUT);
pinMode(13,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState13=digitalRead(13);
delay(10);
buttonState10=digitalRead(10);
delay(10);

if(buttonState13==1 && buttonState10==1){
  Serial.print("Both PIN is pressed");
}

else if(buttonState10==1){
  Serial.print("10 PIN is pressed");
}

else if(buttonState13==1){
  Serial.print("13 PIN is pressed");
}

else{
  //Do nothing
}
delay(10);
}
