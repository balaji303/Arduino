void setup()
{
//  pinMode(4, INPUT);
Serial.begin(9600);

}


void loop()
{

    Serial.println(analogRead(A0));
    delay(1000);

}
