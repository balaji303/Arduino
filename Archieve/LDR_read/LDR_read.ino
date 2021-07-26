void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int var,rea;
 rea=analogRead(A0);
 var=map(rea,0,700,0,13);
 Serial.println(var);
 delay(303);
}
