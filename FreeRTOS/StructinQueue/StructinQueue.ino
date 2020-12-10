#include <Arduino_FreeRTOS.h>

#include <queue.h>

struct Arduino{
  int pin;
  int ReadValue;
}

QueueHandle_t structQueue;
void setup() {
  // put your setup code here, to run once:
structQueue=xQueueCreate(10,sizeof(structQueue));
if(structQueue!=NULL){
  xTaskCreate(TaskLED,
              "TaskLED",
              );
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
