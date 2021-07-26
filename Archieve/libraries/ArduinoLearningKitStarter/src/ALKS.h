#pragma once

#include "Arduino.h"

static const uint32_t DEFAULT_SERIAL_SPEED = 115200;

#ifdef LegALKS
static const uint8_t L_R = 12;
static const uint8_t L_G = 7;
static const uint8_t L_Y = 13;
static const uint8_t L_B = 8;
static const uint8_t L_RGB_R = 5;
static const uint8_t L_RGB_G = 11;
static const uint8_t L_RGB_B = 6;

static const uint8_t SW1 = 2;
static const uint8_t SW2 = 4;
static const uint8_t SW3 = 3;

static const uint8_t POT1 = A0;
static const uint8_t POT2 = A1;

static const uint8_t PIEZO1 = 9;
static const uint8_t PIEZO2 = 10;

static const uint8_t PHOTO = A2;

static const uint8_t DHT_PIN = A3;

#elif defined(AVR)
static const uint8_t D0 = 0;
static const uint8_t D1 = 1;
static const uint8_t D2 = 2;
static const uint8_t D3 = 3;
static const uint8_t D4 = 4;
static const uint8_t D5 = 5;
static const uint8_t D6 = 6;
static const uint8_t D7 = 7;
static const uint8_t D8 = 8;
static const uint8_t D9 = 9;
static const uint8_t D10 = 10;
static const uint8_t D11 = 11;
static const uint8_t D12 = 12;
static const uint8_t D13 = 13;

static const uint8_t L_R = 12;
static const uint8_t L_G = 7;
static const uint8_t L_Y = 13;
static const uint8_t L_B = 8;
static const uint8_t L_RGB_R = 5;
static const uint8_t L_RGB_G = 11;
static const uint8_t L_RGB_B = 6;

static const uint8_t SW1 = 2;
static const uint8_t SW2 = 3;
static const uint8_t SW3 = 4;

static const uint8_t POT1 = A0;
static const uint8_t POT2 = A1;

static const uint8_t PIEZO1 = 9;
static const uint8_t PIEZO2 = 10;

static const uint8_t PHOTO = A2;

static const uint8_t DHT_PIN = A3;

static const uint8_t S1 = 5;
static const uint8_t S2 = 6;
static const uint8_t S3 = 9;
static const uint8_t S4 = 10;
static const uint8_t S5 = 11;

#elif defined(ALKSESP32) // If ALKS ESP32 board variant is selected, do not map pins again

#elif defined(ESP32)
static const uint8_t D0 = 40;
static const uint8_t D1 = 41;
static const uint8_t D2 = 15;
static const uint8_t D3 = 2;
static const uint8_t D4 = 0;
static const uint8_t D5 = 4;
static const uint8_t D6 = 16;
static const uint8_t D7 = 17;
static const uint8_t D8 = 5;
static const uint8_t D9 = 18;
static const uint8_t D10 = 19;
static const uint8_t D11 = 21;
static const uint8_t D12 = 22;
static const uint8_t D13 = 23;

/* to use these pins you have to use ALKS ESP32 board variant instead
static const uint8_t A0 = 32;
static const uint8_t A1 = 33;
static const uint8_t A2 = 25;
static const uint8_t A3 = 26;
static const uint8_t A4 = 27;
static const uint8_t A5 = 14;
static const uint8_t A6 = 12;
static const uint8_t A7 = 15;

static const uint8_t SDA = 27;
static const uint8_t SCL = 14;

static const uint8_t SS    = 19;
static const uint8_t MOSI  = 21;
static const uint8_t MISO  = 22;
static const uint8_t SCK   = 23;
*/

static const uint8_t L_R = 22;
static const uint8_t L_G = 17;
static const uint8_t L_Y = 23;
static const uint8_t L_B = 5;
static const uint8_t L_RGB_R = 4;
static const uint8_t L_RGB_G = 21;
static const uint8_t L_RGB_B = 16;

static const uint8_t SW1 = 15;
static const uint8_t SW2 = 2;
static const uint8_t SW3 = 0;

static const uint8_t POT1 = 32;
static const uint8_t POT2 = 33;

static const uint8_t PIEZO1 = 19;
static const uint8_t PIEZO2 = 18;

static const uint8_t PHOTO = 25;

static const uint8_t DHT_PIN = 26;

static const uint8_t S1 = 4;
static const uint8_t S2 = 16;
static const uint8_t S3 = 18;
static const uint8_t S4 = 19;
static const uint8_t S5 = 21;

#else
  #error "Selected unsupported platform/processor!"
#endif

//alias for some pins/peripheries
static const uint8_t LED_RED = L_R;
static const uint8_t LED_GREEN = L_G;
static const uint8_t LED_YELLOW = L_Y;
static const uint8_t LED_BLUE = L_B;
static const uint8_t LED_RGB_RED = L_RGB_R;
static const uint8_t LED_RGB_GREEN = L_RGB_G;
static const uint8_t LED_RGB_BLUE = L_RGB_B;

static const uint8_t SERVO1 = S1;
static const uint8_t SERVO2 = S2;
static const uint8_t SERVO3 = S3;
static const uint8_t SERVO4 = S4;
static const uint8_t SERVO5 = S5;

void setupLeds();
void setupRgbLed();
void setupButtons();
void setupPiezo();
void setupAll();
