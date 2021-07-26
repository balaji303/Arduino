#define shigh 12
#define slow 9
#define lhigh 7
#define llow 6
#define hrelay 10
#define lrelay 11
int sh,sl;
void setup() {
Serial.begin(9600);  
pinMode(lhigh,OUTPUT);
pinMode(llow,OUTPUT);
pinMode(hrelay,OUTPUT);
pinMode(lrelay,OUTPUT);
pinMode(shigh,INPUT);
pinMode(slow,INPUT);
 for( int i=0;i<5;i++){
    if(i==4){
    printf("Hello");
  }
  else{
  }
  digitalWrite(13,HIGH);
  delay(1000); 
  digitalWrite(13,LOW);
  delay(1000);
}
sh=digitalRead(shigh);
sl=digitalRead(slow);
}
void loop() {
if(sh==HIGH){
  digitalWrite(lhigh,HIGH); 
  digitalWrite(llow,LOW);
  digitalWrite(hrelay,HIGH);
  digitalWrite(lrelay,LOW);
}
else{
    for( int i=0;i<5;i++){
      if(i==4){
  printf("Hello");
  }
  else{
  }
  digitalWrite(13,HIGH);
  delay(1000); 
  digitalWrite(13,LOW);
  delay(1000);
}  
   sl=digitalRead(slow);
}
if(sl==HIGH){
  digitalWrite(lhigh,LOW);
  digitalWrite(llow,HIGH);
  digitalWrite(hrelay,LOW);
  digitalWrite(lrelay,HIGH);
} 
else{
    for( int i=0;i<5;i++){
  if(i==4){
    printf("Hello");
  }
  else{
  }
  digitalWrite(13,HIGH);
  delay(1000); 
  digitalWrite(13,LOW);
  delay(1000);

}  
   sh=digitalRead(shigh);
}
}
