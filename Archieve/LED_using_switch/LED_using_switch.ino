#define s 5
#define led 4
int sa;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("START");
pinMode(led,OUTPUT);
pinMode(s,INPUT);
digitalWrite(led,HIGH);
delay(1000);
digitalWrite(led,LOW);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
sa=digitalRead(s);  
if(sa==HIGH){
Serial.println("ON");
digitalWrite(led,HIGH);
delay(300);
digitalWrite(led,LOW);
delay(300);
digitalWrite(led,HIGH);
delay(400);
digitalWrite(led,LOW);
delay(400);
digitalWrite(led,HIGH);
delay(300);
digitalWrite(led,LOW);
delay(300);
digitalWrite(led,HIGH);
delay(400);
digitalWrite(led,LOW);
delay(400);}
else{
Serial.println("....");
digitalWrite(led,LOW);
delay(1000);
}
}
