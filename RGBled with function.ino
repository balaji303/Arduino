#define R 9
#define G 10
#define B 11
void setup() {
  // put your setup code here, to run once:
 pinMode(G,OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 red();
 blue();
 green();
 blue();
 red();
 green();
 blue();
 
}
void red(){
  digitalWrite(R,HIGH);
  delay(1303);
  digitalWrite(R,LOW);
}

void blue(){
  digitalWrite(B,HIGH);
  delay(1303);
  digitalWrite(B,LOW);
}
void green(){
  digitalWrite(G,HIGH);
  delay(1303);
  digitalWrite(G,LOW);
}
