#define r 5
#define g 6
#define w 7
void setup() {
  
Serial.begin(9600);
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(w,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int var;
 var = analogRead(A0);
 if(var>300){
  Serial.println("Not Touching");
  digitalWrite(r,HIGH);
  delay(2000);
  digitalWrite(r,LOW);
 }
 else if(var<300 && var >280){
  Serial.println("Touching");
  digitalWrite(g,HIGH);
  delay(2000);
  digitalWrite(g,LOW);
 }
 else{
  Serial.println("Cooling");
  digitalWrite(w,HIGH);
  delay(2000);
  digitalWrite(w,LOW);
 }
}
