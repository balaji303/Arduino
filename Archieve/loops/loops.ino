void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(int i=0;i<5;i++){
  Serial.println(i);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<6;i++){
  
  if(i==4){
    break;
  }
  else{
    Serial.println(i);
  delay(1000);
  }
}
}
