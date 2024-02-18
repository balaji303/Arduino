int volt;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
volt=analogRead(A0);
volt=map(volt,0,1024,0,12);
Serial.print(volt);
Serial.println("V");
delay(2000);
}
