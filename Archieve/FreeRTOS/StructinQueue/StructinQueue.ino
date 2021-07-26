#include <Arduino_FreeRTOS.h>

#include <queue.h>

struct Arduino{
  int pin;
  int ReadValue;
};
void Blink(void *param);
void POT1(void *param);
void POT2(void *param);
void PrintSerial(void *param);
QueueHandle_t structQueue;
void setup() {
  // put your setup code here, to run once:
structQueue=xQueueCreate(10,sizeof(struct Arduino));
if(structQueue!=NULL){
  xTaskCreate(Blink,
              "TaskLED",
              128,
              NULL,
              2,
              NULL);
  xTaskCreate(POT1,
              "AnalogRead1",
              128,
              NULL,
              2,
              NULL);
   xTaskCreate(POT2,
              "AnalogRead2",
              128,
              NULL,
              2,
              NULL);
   xTaskCreate(PrintSerial,
              "PrintSerial",
              128,
              NULL,
              1,
              NULL);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  //Do nothing
}
void Blink(void *param){
  (void) param;
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  while(1){
    digitalWrite(13,HIGH);
    vTaskDelay(250/portTICK_PERIOD_MS);
    digitalWrite(13,LOW);
    vTaskDelay(250/portTICK_PERIOD_MS);
  }
}

void POT1(void *param){
  (void) param;
  while(1){
  struct Arduino var1;
  var1.pin=0;
  var1.ReadValue=analogRead(A0);

  xQueueSend(structQueue,&var1,portMAX_DELAY);
  vTaskDelay(1);
  }
}

void POT2(void *param){
  (void) param;
  while(1){
  struct Arduino var2;
  var2.pin=1;
  var2.ReadValue=analogRead(A1);
  xQueueSend(structQueue,&var2,portMAX_DELAY);
  vTaskDelay(1);
  }
}

void PrintSerial(void *param){
  (void) param;
  Serial.begin(9600);
  while(1){
    struct Arduino var1;
    struct Arduino var2;
    if(xQueueReceive(structQueue,&var1,portMAX_DELAY) == pdPASS ){
      Serial.print("PIN:");
      Serial.println(var1.pin);
      Serial.print("value:");
      Serial.println(var1.ReadValue);
    }

    if(xQueueReceive(structQueue,&var2,portMAX_DELAY)==pdPASS){
      Serial.print("PIN:******");
      Serial.println(var2.pin);
      Serial.println(var2.ReadValue);
      Serial.println("******");
    }
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}
