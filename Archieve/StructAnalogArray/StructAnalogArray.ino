struct Arduino{
  int pin[2];
  int value[2];
};
struct Arduino readvalue;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(A1,INPUT);
Serial.begin(9600);
readvalue.pin[0]=0;
readvalue.pin[1]=1;
readvalue.value[0]=1;
readvalue.value[1]=2000;
Serial.print("PIN: ");
Serial.println(readvalue.pin[0]);
Serial.print("VALUE: ");
Serial.println(readvalue.value[0]);
delay(500);
Serial.print("PIN: ");
Serial.println(readvalue.pin[1]);
Serial.print("VALUE: ");
Serial.println(readvalue.value[1]);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
}
