void setup() {
  // put your setup code here, to run once:
  pinMode(16, OUTPUT);
  pinMode(05,OUTPUT);
  pinMode(04,OUTPUT);
  pinMode(02,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(05, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(04, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
 digitalWrite(16, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(02, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
    digitalWrite(02, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
   digitalWrite(16, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
   digitalWrite(04, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
    digitalWrite(05, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second  
}
