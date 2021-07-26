#define g A1 //1 pot to A1
#define w A2 //2 pot to A2
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Green:");
Serial.print(analogRead(g));
Serial.print("\t");
Serial.print("White:");
Serial.println(analogRead(w));
delay(300);
}
