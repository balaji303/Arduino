void setup() {
pinMode(A0,INPUT);
pinMode(16,OUTPUT);
Serial.begin(9600);
}
void loop() {
int moisture;
moisture=analogRead(A0);//Reads analog value
if(moisture<1000){
digitalWrite(07,HIGH); //enables Motor
Serial.println("WATER is there so happy");
}
else
{
digitalWrite(07,LOW);
Serial.println("WATER Needed");
}
delay(1000);
}
