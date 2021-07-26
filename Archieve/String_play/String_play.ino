String word1;
void setup() {
  // put your setup code here, to run once:
//word1="";
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//word1="";
word1="Welcome";
Serial.println(word1);
Serial.println(word1.length());
Serial.println(word1.compareTo("Welco"));
Serial.println(word1.indexOf('c'));
delay(99999)

;}
