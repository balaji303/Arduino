int led = 11;
int brightness = 2;

void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(led,brightness);
//increase the brightness
 brightness=brightness+10;
//wait for 1 secound 
 delay(1000);
}
