const int a=47;
int b=2;
float e=4.1;
float f=2.2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
int a=1;
int c;
fun(c);
func(a,b);
Serial.println(refun(e,f));
}

void loop() {
  
  // put your main code here, to run repeatedly:

}
int fun(int){
  int c=3;
  Serial.println(c);
}
void func(int num1,int num2){
  Serial.println(a);
  Serial.println(num1+num2);
}
int refun(float num1,float num2)
{
  return(float(num1*num2));
}
