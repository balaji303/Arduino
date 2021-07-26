void setup() {
  pinMode(04,OUTPUT);
  pinMode(02,OUTPUT);
  pinMode(03,OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome!");  
}
void loop() {
  for(int count=0;count<10;count++){
  if(count <5)
   {
    Serial.println(count );
    Serial.print(" is the value of Count and it is less than 5\n");
    digitalWrite(04,HIGH);
    Serial.println("White");
    delay(1500);
    digitalWrite(04,LOW);   
   }
   else if(count>5 && count <10)
   {
    Serial.println(count );
    Serial.print("is the value of Count and is greater than 5\n");
    digitalWrite(02,HIGH);
    Serial.println("Red");
    delay(1500);
    digitalWrite(02,LOW);
   }
   else
   {
    Serial.println(count);
    Serial.println("is equal to 5");
    digitalWrite(03,HIGH);
    Serial.println("Green");
    delay(1500);
    digitalWrite(03,LOW);
   }  
}
}
