/**
 * @file UART_Rx.ino
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Control the LED via UART of another device
 * @version 1
 * @date 20-09-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
#include <SoftwareSerial.h>
// Global variables
char databyte;  

/**
 * @brief Function that runs once
 * 
 */
void setup()
{
  // Set the Serial Communication at baud rate 9600
  Serial.begin(9600);
  // Enable build-in LED pin at 13 as output pin
  pinMode(13,OUTPUT);
}

/**
 * @brief Function that keeps running
 * 
 */
void loop() 
{
  //! Read the serial port and get the data
  databyte = Serial.read();
  // Check if data is present 
  if (databyte > -1)
  {
    // If 0 is received reset the LED
    if (databyte == '0')
    {
      digitalWrite(13,LOW);
      delay(1000);
    } // end of if
    //! If 1 is received set the LED
    else if(databyte == '1')
    {
      digitalWrite(13,HIGH);
      delay(1000);
      digitalWrite(13,LOW);
      delay(1000);
    } // end of else if
    // If other input received reset the LED
    else
    {
      digitalWrite(13,LOW);
    } // end of else
  } // end of databyte check
} // end of loop() function
