int var;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 var=analogRead(A0);
 Serial.println(var);
 int mappedVar=map(var,0,1023,0,255);
 digitalWrite(3,mappedVar);
 delay(1000);
 
}
