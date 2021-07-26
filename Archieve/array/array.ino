char c[6]={"Balaji"};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(int i=0;i<6;i++){
Serial.println(c[i]);
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
