int a=130;
#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  
 myservo.attach(9);
delay(1000);
Serial.println("Start"); 
     myservo.write(0);
    delay(1000);
    myservo.write(a);
    delay(1000);
    myservo.write(0);
    delay(1000);
    myservo.write(a);
    delay(1000);
    myservo.write(0);
    delay(1000);
    myservo.write(a);
    delay(1000);
    myservo.write(0);
    delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
