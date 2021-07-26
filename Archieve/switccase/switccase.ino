int c=1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
switch(c){
  case 1:
     Serial.println("1 is pressed");
     break;
  case 2:
     Serial.println("2 is pressed");
     break;
  default:
     Serial.println("The default is pressed");
     break;
  
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
