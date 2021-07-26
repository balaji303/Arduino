//ln means end  of the line 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
Serial.println("1"); //output:        1 24  3
Serial.print("2");
Serial.println("4");
Serial.print("3");
}
