#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequencyR = 0;
int frequencyB = 0;
int frequencyG = 0;
int average=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
  Serial.println("Start");
}
void loop() {
  delay(1000);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  delay(4000);
  frequencyR = pulseIn(sensorOut, LOW);
  Serial.print("R= ");
  Serial.print(frequencyR);
  Serial.print("  ");  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  delay(4000);
  frequencyG = pulseIn(sensorOut, LOW);
  Serial.print("G= ");
  Serial.print(frequencyG);
  Serial.print("  ");
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  delay(4000);
  frequencyB = pulseIn(sensorOut, LOW); 
  Serial.print("B= ");
  Serial.print(frequencyB);
  Serial.println("  ");
  average=(frequencyB+frequencyG+frequencyR)/3;
  //Serial.println(average);
}
