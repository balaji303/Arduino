#include "lcd.h"
#include "gsm.h"
#include "dht11.h"
#include "ultrasonic.h"
ULTRASONIC saline;
DHT dht;
int HB = 2;
int x_axis = A1;
int respiratory = 3;
void iot(String stringdata);
int heart();
void setup()
{
 // put your setup code here, to run once:
 lcd.begin(16, 2);
 Serial1.begin(9600); //gsm(TX1)
 Serial2.begin(9600); //iot(TX0)
 saline.begin(4, 5);
 pinMode(7, INPUT); //(LO-)LEADS-OFF DETECT- IN ECG
 pinMode(6, INPUT); //(LO+)LEADS-OFF DETECT+ IN ECG
 pinMode(A0, INPUT); //OUTPUT IN ECG
 pinMode(HB, INPUT);
 pinMode(respiratory, INPUT);
 pinMode(x_axis, INPUT);
 dht.dht_read(30);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("patient health");
 lcd.setCursor(0, 1);
 lcd.print("monitoring");
 delay(2000);
}
void loop()
{
 // put your main code here, to run repeatedly:
 dht.dht_read(30);
 int heart_rate = heart();
 int trip_level = saline.ultra();
 int breath = digitalRead(respiratory);
 int body_movement = analogRead(x_axis);
 int ecg = analogRead(A0);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("T:" + String(dht.temperature));
 lcd.setCursor(4, 0);
 lcd.print("HB:" + String(heart_rate));
 lcd.setCursor(10, 0);
 lcd.print("TL:" + String(trip_level));
 lcd.setCursor(0, 1);
 lcd.print("Axis:" + String(body_movement));
 lcd.setCursor(8, 1);
 lcd.print("ECG:" + String(ecg));
 delay(2000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("R:" + String(breath));
 delay(1000);3
 if (heart_rate > 60 && heart_rate < 70)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("heart normal");
 lcd.setCursor(0, 1);
 lcd.print("SpO2 = 95%");
 delay(1000);
 }
 if (heart_rate > 71 && heart_rate < 80)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("heart normal");
 lcd.setCursor(0, 1);
 lcd.print("SpO2 = 96%");
 delay(1000);
 }
 if (heart_rate > 81 && heart_rate < 90)
 {
 lcd.clear();
 lcd.setCursor(0, 0);3
 lcd.print("heart normal");
 lcd.setCursor(0, 1);
 lcd.print("SpO2 = 97%");
 delay(1000);
 }
 if (heart_rate > 91 && heart_rate < 95)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("heart normal");
 lcd.setCursor(0, 1);
 lcd.print("SpO2 = 98%");
 delay(1000);
 }
 if (heart_rate > 96 && heart_rate < 100)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("heart normal");
 lcd.setCursor(0, 1);
 lcd.print("SpO2 = 99%");
 delay(1000);
 }
 if (heart_rate > 101 && heart_rate < 130)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("heart abnormal");
 lcd.setCursor(0, 1);
 lcd.print("SpO2 = 93%");
 send_sms("9080311840", "Patient ID: 1, heart abnormal");
 iot("*Patient ID: 1, heart abnormal#");
 }
 if (heart_rate >= 0 && heart_rate < 59)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("heart abnormal");
 lcd.setCursor(0, 1);
 lcd.print("SpO2 = 94%");
 send_sms("9080311840", "Patient ID: 1, heart abnormal");
 iot("*Patient ID: 1, heart abnormal#");
 }
 if (breath == 0)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("person no breath");
 send_sms("9080311840", "Patient ID: 1, person no breath");
 iot("*Patient ID: 1, person no breath#");3
 }
 else
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("person breathing");
 }
 if (dht.temperature > 32)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("temperature high");
 send_sms("9080311840", "Patient ID: 1, temperature high");
 iot("*Patient ID: 1, temperature high#");
 }
 if (body_movement < 500)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("person moved");
 send_sms("9080311840", "Patient ID: 1, person moved");
 iot("*Patient ID: 1, person moved#");
 }
 if (trip_level > 10 && trip_level < 15)
 {
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("saline level low");
 send_sms("9080311840", "Patient ID: 1, saline level low");
 iot("*Patient ID: 1, saline level low#");
 }
}
int heart()
{
 int j = 120;
 int i = 0;
 while (j > 0)
 {
 if (digitalRead(HB) == LOW)
 i++;
 j--;
 delay(14);
 }
 delay(1000);
 return i;
}
void iot(String stringdata) //iot function
{
 for (int i = 0; i < stringdata.length(); i++)
 {
 Serial2.write(stringdata[i]);
 }
 delay(1000);
}
