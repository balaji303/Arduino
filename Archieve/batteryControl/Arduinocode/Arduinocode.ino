//Code for arduino
int a;
void setup() {

  pinMode(8,OUTPUT);
  Serial.begin(9600);
  analogWrite(A2,0);
  pinMode(4,OUTPUT);

}
void loop() {
digitalWrite(8,HIGH);
a=analogRead(A2);
if(a>200){
  Serial.println("RELAY ON");
  digitalWrite(4,LOW);
}
else{
  Serial.println("Relay OFF");
  digitalWrite(4,HIGH);
}
delay(2000);
}
//void setup(){
//Serial.begin(9600);
//analogWrite(A2,0);
//}
//void loop(){
//Serial.println(analogRead(A2));
//delay(1000);
//}
