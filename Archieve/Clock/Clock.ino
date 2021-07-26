void setup(){
  Serial.begin(9600);
  pinMode(04,OUTPUT);
}
void loop(){
  int now=millis();
  Serial.println(now);
  Serial.println(".");
  delay(500);
//  clear(now);
//  Serial.println(now);
//  Serial.println("..");
  long unsigned int n=millis();
  Serial.println(n);
  Serial.println("...");
//  delay(500);
//  if(now>500&&now<1000){
//    Serial.println("5");
//    digitalWrite(04,HIGH);
//    delay(500);
//    digitalWrite(04,LOW);
//  }
//  else{
//    Serial.println(",");
//  }
//  delay(100);
//  now=0;
}
