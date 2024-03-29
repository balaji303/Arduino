/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  Blynk using a LED widget on your phone!

  App project setup:
    LED widget on V1
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "tS6foVtkdqfiJUSOM164-jNNK8HlDUhf";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JINKALALA";
char pass[] = "BALAJIbalaji";

WidgetLED led1(D0);
WidgetLED led1(D1);
WidgetLED led1(D2);

BlynkTimer timer;
bool ledStatus = false;

#define BLYNK_GREEN     "#23C48E"
#define BLYNK_BLUE      "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (ledStatus) {
    led1.setColor(BLYNK_RED);
    Serial.println("LED on V1: red");
    ledStatus = false;
  } else {
    led1.setColor(BLYNK_GREEN);
    Serial.println("LED on V1: green");
    ledStatus = true;
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Turn LED on, so colors are visible
  led1.on();
  // Setup periodic color change
  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
