void setup() {
  pinMode(01, OUTPUT);
  pinMode(02, OUTPUT);
  pinMode(03, OUTPUT);
}
void loop() {
  digitalWrite(04, HIGH);   
  delay(1000);              
  digitalWrite(04, LOW);    
  delay(1500);  
  digitalWrite(02, HIGH);   
  delay(1000);              
  digitalWrite(02, LOW);    
  delay(1500);  
  digitalWrite(03, HIGH);   
  delay(1000);              
  digitalWrite(03, LOW);    
  delay(1500);  
}
