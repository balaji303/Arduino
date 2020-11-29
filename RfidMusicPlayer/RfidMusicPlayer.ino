#include <SPI.h>
#include <MFRC522.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#define RST_PIN         9           
#define SS_PIN          10
          
boolean isPlaying = false;
MFRC522 mfrc522(SS_PIN, RST_PIN);  
SoftwareSerial mySoftwareSerial(5, 6); 

DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);


void setup() {
  Serial.begin(115200);                                        
  mySoftwareSerial.begin(9600);
  SPI.begin();                                                 
  mfrc522.PCD_Init();                                          

  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
  }
  Serial.println(F("DFPlayer Mini online. Place card on reader to play a spesific song"));

  myDFPlayer.volume(20);  //Set volume From 0 to 30 

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
}

void loop() {
  
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  byte block;
  byte len;
  MFRC522::StatusCode status;

  
  if ( mfrc522.PICC_IsNewCardPresent()) {

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      return;
    }

    Serial.println(F("**Card Detected:**"));

    mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid)); //print card details

    Serial.print(F("Number: "));
    
    byte buffer2[18];
    block = 1;
    len = 18;

    //If card is failed to read
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); 
    if (status != MFRC522::STATUS_OK) {
      Serial.print(F("Authentication failed: "));
      Serial.println(mfrc522.GetStatusCodeName(status));
      return;
    }

    //If card is failed to read
    status = mfrc522.MIFARE_Read(block, buffer2, &len);
    if (status != MFRC522::STATUS_OK) {
      Serial.print(F("Reading failed: "));
      Serial.println(mfrc522.GetStatusCodeName(status));
      return;
    }


 
    String number = "";

    for (uint8_t i = 0; i < 16; i++)
    {
      number += (char)buffer2[i];
    }
    number.trim();
    Serial.print(number); //Print number of the card



    myDFPlayer.play(number.toInt()); //Play song that matches the number
    isPlaying = true;

    Serial.println(F("\n**End Reading**\n"));

    delay(1000);

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}
