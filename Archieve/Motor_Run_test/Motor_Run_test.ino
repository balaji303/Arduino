void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(9,HIGH);
delay(1000);
digitalWrite(9,LOW);
delay(1000);
}
