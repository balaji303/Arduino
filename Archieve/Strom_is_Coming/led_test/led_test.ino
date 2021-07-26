// Cant have a loop that ends
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
 Serial.begin(9600);
 for( int i=0;i<5;i++){
  digitalWrite(13,HIGH);
  delay(1000); 
  digitalWrite(13,LOW);
  delay(1000);
  
  if(i==4){
    printf("Hello....");
  }
  else{
  }
}
 
 
Serial.println("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
