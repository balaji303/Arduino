#define R 9
#define G 10
#define B 11
int j,i,k=0;
void setup() {
  // put your setup code here, to run once:
 pinMode(G,OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 for( i=0;i<256;i++){//for RED
  digitalWrite(B,k);
  
   for( j=0;j<256;j++){//for Green
    digitalWrite(G,j);
    digitalWrite(B,k);
     for( k=0;k<256;k++){
      digitalWrite(G,j);
      digitalWrite(R,i);
      
     }
   }
 }
}
