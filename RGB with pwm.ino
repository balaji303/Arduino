#define RED 9
#define GREEN 10
#define BLUE  11
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(BLUE,OUTPUT);
digitalWrite(RED,LOW);
digitalWrite(BLUE,LOW);
digitalWrite(GREEN,LOW);
delay(1000);
digitalWrite(RED,HIGH);
delay(1000);
digitalWrite(BLUE,HIGH);
delay(1000);
digitalWrite(GREEN,HIGH);
delay(1000);
digitalWrite(RED,LOW);
digitalWrite(BLUE,LOW);
digitalWrite(GREEN,LOW);

}
void loop() {
  // put your main code here, to run repeatedly:
 analogWrite(RED,255);
 analogWrite(GREEN,255);
 analogWrite(BLUE,0);
}
