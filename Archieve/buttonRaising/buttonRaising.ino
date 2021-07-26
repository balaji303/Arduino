void setup() {
  // put your setup code here, to run once:
pinMode(7,INPUT);
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(LED_BUILTIN,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(7)==LOW){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
}
else{
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);  
}
delay(1000);
}
