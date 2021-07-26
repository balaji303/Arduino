#define r1 9
#define r2 8
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,HIGH);    
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
Serial.println("2 pin or 1st Relay");
delay(5000);
digitalWrite(r2,HIGH);
digitalWrite(r1,LOW);
Serial.println("***4 pin or 2st Relay***");
delay(5000);
}
