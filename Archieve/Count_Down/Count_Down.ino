int d;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Start");
for(d=10;d>0;--d){
  Serial.println(d);
  delay(1000);
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
