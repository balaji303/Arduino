void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int var=0;
 var=analogRead(A0);
 Serial.println(var);
 delay(1000);
}
