/**
 * @file UART_Tx.ino
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Send array to another device using UART
 * @version 1
 * @date 20-09-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */

#include <SoftwareSerial.h>
#define MAX_INDEX 4
// Global variables
char databyte[MAX_INDEX]={'0','1','1','0'};  
int index = 0;

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
  // If 1 is sent, glow the LED in Tx-Board
  if (databyte[index] == '1')
  {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
  }

  if (databyte[index] == '0' || databyte[index] == '1')
  {
    // ! Send data via UART
    Serial.write(&databyte[index],1);
    delay(1000);
  }
  // Reset the index
  if( index > MAX_INDEX )
  {
    index = 0;
  }
  else
  {
    index++;
  }// end of else
}// end of loop() function
