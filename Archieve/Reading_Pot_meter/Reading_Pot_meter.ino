int var;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
var=analogRead(A0);
delay(1000);
Serial.println(var);
if(var<100){
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(2,LOW);
}
else if(var>100 && var<200){
  digitalWrite(3,HIGH);
  delay(1000);
  digitalWrite(3,LOW);
}
else{
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(4,LOW);
}
}
