#include"ultrasonic.h"


void begin(int trigger_pin, int echo_pin);
int ultra(void);

void ULTRASONIC::begin(int trigger_pin, int echo_pin)
{
  trig = trigger_pin;
  echo = echo_pin;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
int ULTRASONIC::ultra()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dist = pulseIn(echo, HIGH);
  dist = (dist / 2) / 29.1;
  return dist;  
}
