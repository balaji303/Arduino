/*
  Conditionals - If statement

 This example demonstrates the use of if() statements.
 It reads the state of a potentiometer (an analog input) and turns on an LED
 only if the potentiometer goes above a certain threshold level. It prints the analog value
 regardless of the level.

 The circuit:
 * potentiometer connected to analog pin 0.
 Center pin of the potentiometer goes to the analog pin.
 side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 13 to ground

 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.

 created 17 Jan 2009
 modified 9 Apr 2012
 by Tom Igoe

This example code is in the public domain.

http://www.arduino.cc/en/Tutorial/IfStatement

 */

// These constants won't change:
const int analogPin = A0;    // pin that the sensor is attached to
const int ledPin1= 16;// pin that the LED is attached to
const int ledPin2= 05;// pin that the LED is attached to
const int ledPin3= 04;// pin that the LED is attached to
const int threshold1 = 400; // an arbitrary threshold level that's in the range of the analog input
const int threshold2 = 500;
const int threshold3 = 600;  
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(A0);

  // if the analog value is high enough, turn on the LED:
  if (analogValue > threshold1) {
    digitalWrite(16, HIGH);
  } else {
    digitalWrite(16, LOW);
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability



  if (analogValue > threshold2) {
    digitalWrite(05, HIGH);
  } else {
    digitalWrite(05, LOW);
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability



  if (analogValue > threshold3) {
    digitalWrite(04, HIGH);
  } else {
    digitalWrite(04, LOW);
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability


  
}
