void setup() {
  // put your setup code here, to run once:
Serial.begin(38400);
Serial.println("The");
Serial.print("program begins");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(millis());
  delay(9600);

}
