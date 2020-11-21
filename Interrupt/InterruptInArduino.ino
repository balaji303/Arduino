volatile byte buttonstate=0; //Initializing Button State
void InSR(void){ //This Function is called when interrupt occurs
  //Interrupt Service Routine
 buttonstate=!buttonstate;    //Changing the state of the button
}

void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);             //Button is connected here
pinMode(13,OUTPUT);           //In-built LED is connected here
attachInterrupt(digitalPinToInterrupt(2),InSR,FALLING); //When PIN 2(button) goes from High to Low i.e., falling interrupt
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,buttonstate); //State of LED is set as Buttonstate
delay(10);                    //A small delay is used
}


