int a;
int num =0;
void setup() {
Serial.begin(9600);  
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(4,INPUT);
for(int i=1;i<6;i++){
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}
}

void loop() {
  // put your main code here, to run repeatedly:
a=digitalRead(4);
if(a==HIGH){
  num=num+1;
}
else{}
if(num%2==0){
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}
else{
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}
}
