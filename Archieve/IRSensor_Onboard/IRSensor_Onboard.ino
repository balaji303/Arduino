void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(5,OUTPUT);
digitalWrite(5,LOW);
pinMode(6,OUTPUT);
digitalWrite(6,OUTPUT);
pinMode(7,INPUT);
pinMode(13,OUTPUT);
digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
char ir=digitalRead(7);
if(ir==1){
  digitalWrite(13,HIGH);
}
else{
  digitalWrite(13,LOW);
  Serial.println("No signal");
}
delay(300);
}
