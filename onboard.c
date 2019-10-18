int X_axis = A3;

int Y_axis = A2;

int Z_axis = A1;

const int groundpin = 18;             // analog input pin 4 -- ground 

                                      // Analog pins can be treated as digital pins. 

                                      // Analog pin 4 corresponds to digital pin 18.

const int powerpin = 19;              // analog input pin 5 -- voltage

                                      // Analog pin 5 corresponds to digital pin 19



int x, y, z;                          // These variables will hold the raw sensor values.                                      


void setup()

{

//  analogReference(EXTERNAL); // This configures the analog to digital converter so that it

                               // uses the AREF voltage. If you have connected the 3.3V

                               // pin to the AREF pin on the Arduino, then the AREF voltage is 3.3V.

                               // If you have pluged the breakout directly into the analog header

                               // leave analogReference commented out.



  // Provide ground and power by using the analog inputs as normal

  // digital pins.  This makes it possible to directly connect the

  // breakout board to the Arduino.  If you use the normal 5V and

  // GND pins on the Arduino, you can remove these lines.

  pinMode(groundpin, OUTPUT);

  pinMode(powerpin, OUTPUT);

  digitalWrite(groundpin, LOW);

  digitalWrite(powerpin, HIGH);

  Serial.begin(9600);      // sets the serial port to 9600

  delay(1000);
}
void loop()

{

  x = analogRead(X_axis);       // read analog input pin 0

  y = analogRead(Y_axis);       // read analog input pin 1

  z = analogRead(Z_axis);       // read analog input pin 1

  Serial.print(x);              // print the raw value in the X axis

  Serial.print(" | \t");           // prints a tab between the numbers

  Serial.print(y);              // print the raw value in the Y axis

  Serial.print(" | \t");           // prints a tab between the numbers

  Serial.print(z);              // print the raw value in the Z axis

  Serial.println();

  

  delay(100);              // wait 100ms for next reading

}
