/****************************
 * A SMART HEALTHCARE MONITORING SYSTEM FOR PATIENTS BY USING IOT
 * 
 * by
 * 
 * PAVITHRA G 211717106084
 * PRAVITHA LAKSHMI C 211717106090
 * PREETHI D 211717106091
 *****************************/
#include"lcd.h" //Library File for LCD Module
#include"gsm.h" //Library File for GSM Module with 2G SIM
#include"dht11.h" //Library File for DHT11 Temperature sensor
#include"ultrasonic.h" //Library File for UltraSonic Sensor for Drip Level sense

/*Sensor Object Declaration*/
ULTRASONIC saline;
DHT dht;

/*Variables*/
int HB = 2;
int x_axis = A1;
int respiratory = 3;

/*Function Declaration*/
void iot(String stringdata);/*Function to send data to LoLink Module*/
int heart(void);  /*Function to read from Heart Rate Sensor*/

void setup() /*Arduino Software Structure, this function runs only once*/
{

  lcd.begin(16, 2); /*LCD display type 16x2*/
  Serial1.begin(9600); //gsm(TX1) /*Baud Rate is set with GSM module as 9600*/
  Serial2.begin(9600); //iot(TX0) /*Baud Rate is set with LoLink module as 9600*/
  saline.begin(4, 5);  /*Ultra Sonic sensor initalizaion*/
  pinMode(7, INPUT);   //(LO-)LEADS-OFF DETECT- IN ECG/*ECG sensor's probe initialization*/
  pinMode(6, INPUT);   //(LO+)LEADS-OFF DETECT+ IN ECG/*ECG sensor's probe initalization*/
  pinMode(A0, INPUT);  //OUTPUT IN ECG /*ECG sensor probe, ECG's Output is connected to Arduino Input*/
  pinMode(HB, INPUT); /*ECG sensor intialization*/
  pinMode(respiratory, INPUT); /*Respiratory sensor Initalization*/
  pinMode(x_axis, INPUT); /*Accelarometer initialization*/
  dht.dht_read(30); /*Read Temp sensor*/
  lcd.clear(); /*Clear screen in LCD module*/
  lcd.setCursor(0, 0); /*Set Cursor ar 0,0 Start point*/
  lcd.print("patient health");/*Print in LCD*/
  lcd.setCursor(0, 1);/*Set Cursor to next line*/
  lcd.print("monitoring");/*Print in LCD*/
  delay(2000);/*Delay so system dont Hang*/
}

void loop()/*Arduino Software Structure, this function runs always(Infinite loop)*/
{
  // put your main code here, to run repeatedly:
  dht.dht_read(30);/*Read Temp sensor*/
  int heart_rate = heart();/*Read Heart rate sensor and store it in heart_rate sensor variable*/
  int trip_level = saline.ultra();/*Read Ultrasonic senor and store it in trip level variable*/
  int breath = digitalRead(respiratory); /*Read respiratory sensor and store it in breath variable*/
  int body_movement = analogRead(x_axis);/*Read xaxis from accelorameter and store it in body movement*/
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
  delay(1000);

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
    lcd.setCursor(0, 0);
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
    iot("*Patient ID: 1, person no breath#");
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

void iot(String stringdata)        //iot function
{
  for (int i = 0; i < stringdata.length(); i++)
  {
    Serial2.write(stringdata[i]);
  }
  delay(1000);
}
