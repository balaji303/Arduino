#define S0 4
#define S1 5
#define S2 6  
#define S3 7
#define sensorOut 8
int i=0,sumR=0,sumG=0,sumB=0,avgR=0,avgG=0,avgB=0;
int frequencyR[5];
int frequencyB[5];
int frequencyG[5];
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
  analogReference(DEFAULT);
  Serial.println("Start");
  for(int i=0;i<5;i++){  //Reading loop
  Serial.println(i);
  delay(5000);           //5sec delay
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequencyR[i]= pulseIn(sensorOut, LOW);
  delay(100);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequencyG[i]= pulseIn(sensorOut, LOW);
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequencyB[i]= pulseIn(sensorOut, LOW); 
  }
  Serial.println("Output");
for(int i=0;i<5;i++){ //Printing values
  Serial.print(i);
  Serial.print("...");
  delay(1000);
  Serial.print("R:");
  Serial.print(frequencyR[i]);
  Serial.print("   G:");
  Serial.print(frequencyG[i]);
  Serial.print("   B:");
  Serial.println(frequencyB[i]);
}
for(int i=0;i<5;i++){ //Sum all array
  delay(1000);
  sumR=sumR+frequencyR[i];
  sumG=sumG+frequencyG[i];
  sumB=sumB+frequencyB[i]; 
}
Serial.print("Average of R:");
avgR=sumR/5;
delay(1000);
Serial.println(avgR);
Serial.print("Average of G:");
avgG=sumG/5;
delay(1000);
Serial.println(avgG);
Serial.print("Average of B:");
avgB=sumB/5;
delay(1000);
Serial.println(avgB);
Serial.println("*******");
Serial.println("The End");
Serial.println("*******");
}
void loop(){}
