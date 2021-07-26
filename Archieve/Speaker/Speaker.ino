#define sound 12
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sound,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(13,HIGH) ;
 tone(sound,100);
 delay(1000);
 //digitalWrite(13,LOW) ;
 noTone(sound);
 delay(1000);
}
