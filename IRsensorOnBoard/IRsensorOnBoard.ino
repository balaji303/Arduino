void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(4,HIGH);//VCC
digitalWrite(5,LOW);//GND
if(digitalRead(6)==HIGH){
digitalWrite(13,HIGH);
delay(1000); 
 }
else{
digitalWrite(13,LOW);
 }
 delay(100);
}
