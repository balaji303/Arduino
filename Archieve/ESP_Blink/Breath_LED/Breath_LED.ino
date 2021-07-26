#define LED     16        // Led in NodeMCU at pin GPIO16 (D0).
#define wifi    2 
#define BRIGHT    200     //max led intensity (1-500)
#define INHALE    1250    //Inhalation time in milliseconds.
#define PULSE     INHALE*1000/BRIGHT
#define REST      1000    //Rest Between Inhalations.

//----- Setup function. ------------------------
void setup() {                
  pinMode(LED, OUTPUT);   // LED pin as output.    
}

//----- Loop routine. --------------------------
void loop() {
  //ramp decreasing intensity, Exhalation (half time):
  for (int i=BRIGHT-1;i>0;i--){
    digitalWrite(wifi, LOW);          // turn the LED on.
    delayMicroseconds(i*10);          // wait
    digitalWrite(wifi, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);  // wait
    i--;
    delay(0);                        //to prevent watchdog firing.
  }
  //ramp increasing intensity, Inhalation: 
  for (int i=1;i<BRIGHT;i++){
    digitalWrite(LED, LOW);          // turn the LED on.
    delayMicroseconds(i*10);         // wait
    digitalWrite(LED, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);   // wait
    delay(0);                        //to prevent watchdog firing.
  }
  for (int i=1;i<BRIGHT;i++){
    digitalWrite(wifi, LOW);          // turn the LED on.
    delayMicroseconds(i*10);         // wait
    digitalWrite(wifi, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);   // wait
    delay(0);                        //to prevent watchdog firing.
  }

  //ramp decreasing intensity, Exhalation (half time):
  for (int i=BRIGHT-1;i>0;i--){
    digitalWrite(LED, LOW);          // turn the LED on.
    delayMicroseconds(i*10);          // wait
    digitalWrite(LED, HIGH);         // turn the LED off.
    delayMicroseconds(PULSE-i*10);  // wait
    i--;
    delay(0);                        //to prevent watchdog firing.
  }
  delay(REST);                       //take a rest...
}
