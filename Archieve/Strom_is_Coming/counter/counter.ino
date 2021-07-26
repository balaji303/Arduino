int num=0;
int a;
void setup() {
pinMode(4,INPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT); //3v
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
a=digitalRead(4);
Serial.println(a);
if(a==HIGH){
  num=num+1;
}
else{}
delay(1000);
Serial.print("num=");
Serial.println(num);
if(num%2==0){
  digitalWrite(10,HIGH); //3
  digitalWrite(11,HIGH); //3 1st
  digitalWrite(12,LOW);  //5 2ed
  digitalWrite(9,LOW);   //5
  delay(1000);
}
else{
  digitalWrite(9,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  delay(1000);
}
}
