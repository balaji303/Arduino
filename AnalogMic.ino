
int currentValue;

int maxValue;

int minValue;

unsigned long timer;

int sampleSpan  = 200; // Amount in milliseconds to sample data

int volume;            // this roughly goes from 0 to 700

int ledpin      = 7;



void setup() 

{

    Serial.begin(9600); 

    pinMode (ledpin, OUTPUT);

    resetValues();

}



void loop() 

{

    currentValue = analogRead(A0);



    if (currentValue < minValue) {

        minValue = currentValue;

    } 

    if (currentValue > maxValue) {

        maxValue = currentValue;

    }



    if (millis() - timer >= sampleSpan) {

        volume = maxValue - minValue;

        //Serial.println(volume);

        resetValues();

    }



    // I arbitrarily select 100 as the value above which the

    //microphone is picking a loud noise.

    if (volume > 400)

    {

      Serial.println("Loud");

      digitalWrite(ledpin,HIGH);

    } else

    {

      Serial.println("Quiet");

      digitalWrite(7,LOW);

    }

     

}



void resetValues()

{

    maxValue = 0;

    minValue = 1024;

    timer = millis(); 

}
