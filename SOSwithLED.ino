int n;
void setup() {
 Serial.begin(9600);
 pinMode(03,OUTPUT);
 pinMode(02,OUTPUT);
 pinMode(07,OUTPUT);
 pinMode(04,OUTPUT);
 pinMode(05,OUTPUT);
 pinMode(06,OUTPUT);
}

void loop() {
  // put your main code here,
 small();
 small();
 small();
 large();
 large();
 large();
 small();
 small();
 small();
 large();
 large();
 large();
}
int high(){
  for(n=02;n<=07;n++){
  digitalWrite(n,HIGH);
  }
}
int low(){
  for(n=02;n<=07;n++){
    digitalWrite(n,LOW);
  }
}
int small(){
  high();
  delay(1000);
  low();
  delay(500);
}
int large(){
  high();
  delay(500);
  low();
  delay(400);
}
