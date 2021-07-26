int var=0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(07,OUTPUT);
 pinMode(04,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 var=digitalRead(04);
 if(var==HIGH){
  digitalWrite(07,HIGH);
  delay(1000);
  Serial.println("HIGH............");
  
  digitalWrite(07,LOW);
  
 }
 else{
 digitalWrite(07,LOW);
 Serial.println("LOW");

 }
}
