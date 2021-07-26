int r=200    ;
#define p 11
#define a 10
#define b 9
void setup() {
  // put your setup code here, to run once:
pinMode(p,OUTPUT);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(p,r);
//analogWrite(a,r);
//analogWrite(b,r);
}
