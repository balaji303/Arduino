/**
 * PIN-16
 * Digital input
 * Print Digital-input
 */
 uint8_t buttonState;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);
}
/**
 * 16th PIN-5V for 1sec
 * delay-500th- msec-Arduino UNO
 */
void loop() {
  // put your main code here, to run repeatedly:
buttonState=analogRead(A0);
delay(1000);
Serial.print("The Button State is:");
  if(buttonState==1){
    Serial.print("HIGH");
  }
  else{
    Serial.print("LOW");
  }
  delay(100);
  Serial.println("");
}
