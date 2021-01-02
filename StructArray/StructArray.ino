/*
 * Example of a basic FreeRTOS queue
 * https://www.freertos.org/Embedded-RTOS-Queues.html
 */

// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>

// Include queue support
#include <queue.h>

struct Arduino{
  int pin[2];
  int ReadValue[2];
};
void Blink(void *param);
void POT1(void *param);
void POT2(void *param);
void PrintSerial(void *param);
QueueHandle_t structArrayQueue;
void setup() {
  // put your setup code here, to run once:
structArrayQueue=xQueueCreate(10,sizeof(struct Arduino));
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
