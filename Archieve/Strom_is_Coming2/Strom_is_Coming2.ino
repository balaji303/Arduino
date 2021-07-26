void setup(){
  pinMode(10,OUTPUT);
  pinMode(4,INPUT);
  pinMode(2,INPUT);
}
void loop(){
  big=digitalRead(4);
  small=digitalRead(2);
  if(big==HIGH){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);    
  }
  else if(small==HIGH){
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
  }
  else{
  big=digitalRead(4);
  small=digitalRead(2);
  }
  
}
