#define S0 4
#define S1 5
#define S2 6  
#define S3 7
#define sensorOut 8
int frequencyR = 0;
int frequencyB = 0;
int frequencyG = 0;
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
  delay(100);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequencyR = pulseIn(sensorOut, LOW);
  Serial.print("R= ");
  Serial.print(frequencyR);
  Serial.print("  ");
  delay(300);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequencyG = pulseIn(sensorOut, LOW);
  Serial.print("G= ");
  Serial.print(frequencyG);
  Serial.print("  ");
  delay(300);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequencyB = pulseIn(sensorOut, LOW); 
  Serial.print("B= ");
  Serial.print(frequencyB);
  Serial.println("  ");
  delay(300);
}
