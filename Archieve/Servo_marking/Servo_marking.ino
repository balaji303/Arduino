#define sky 25
#define vio 50
#define blu 80
#define yel 110
#define gre 140
#define red 170
#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9);
delay(1000);
Serial.println("Start");  
myservo.write(sky);
delay(1000);
myservo.write(vio);
delay(1000);
myservo.write(blu);
delay(1000);
myservo.write(yel);
delay(1000);
myservo.write(gre);
delay(1000);
myservo.write(red);
delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
