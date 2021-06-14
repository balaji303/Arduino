void setup(void){
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
}
void loop(void){
   if(digitalRead(2)==HIGH){
     digitalWrite(8,HIGH);
     digitalWrite(9,LOW);
     delay(500);
   }
   else if(digitalRead(3)==HIGH){
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    delay(500);
   }
   else{
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    delay(100);
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
    delay(100);
   }
}
