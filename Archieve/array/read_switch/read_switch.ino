int stack6[5],stack5[5],stack7[5];
int sum5=0,sum6=0,sum7=0,avg5=0,avg6=0,avg7=0;
int avg=0,tot=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
analogReference(DEFAULT);
Serial.println("Start");
for(int i=0;i<5;i++){  //Reading loop
  Serial.println(i);
  delay(2000);
  stack5[i]=analogRead(5);
  stack6[i]=analogRead(6);
  stack7[i]=analogRead(7);
}
Serial.println("Output");
for(int i=0;i<5;i++){
  Serial.println(stack5[i]);
  Serial.println(stack6[i]);
  Serial.println(stack7[i]);
}
for(int i=0;i<5;i++){
  sum5=sum5+stack5[i];
  sum6=sum6+stack6[i];
  sum7=sum7+stack7[i];
}
delay(1000);
Serial.println("Average of 5thPIN");
avg5=sum5/5;
Serial.println(avg5);
delay(1000);
Serial.println("Average of 6thPIN");
avg6=sum6/5;
Serial.println(avg6);
delay(1000);
Serial.println("Average of 7thPIN");
avg7=sum7/5;
Serial.println(avg7);
tot=sum5+sum6+sum7;
avg=tot/3;
delay(1000);
Serial.print("Final Total  .-");
Serial.println(tot);
Serial.print("      Average.-");
Serial.println(avg);
}

void loop() {
  // put your main code here, to run repeatedly:

}
