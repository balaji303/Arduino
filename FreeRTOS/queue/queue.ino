#include <Arduino_FreeRTOS.h>
#include <queue.h>

QueueHandle_t outputQueue;
TaskHandle_t taskHand1,taskHand2,taskHand3;
void TaskBlink(void *param);
void TaskSerial(void *param);
void TaskRead(void *param);
void setup() {
  // put your setup code here, to run once:
outputQueue=xQueueCreate(10,sizeof(int));
if(outputQueue!=NULL){
xTaskCreate(
  TaskSerial,
  "PrintTask",
  128,
  NULL,
  2,
  &taskHand1
  );
xTaskCreate(
  TaskRead,
  "AnalogRead",
  128,
  NULL,
  1,
  &taskHand2
  );  
  xTaskCreate(
  TaskBlink,
  "BlinkTask",
  128,
  NULL,
  3,
  &taskHand3
  );
}
}//end of setup

void loop() {
  // put your main code here, to run repeatedly:
}

void TaskBlink(void *param){
 (void)param;
 DDRB |= 0x20;
 while(1){
  PORTB |= 0x20;
  vTaskDelay(250/portTICK_PERIOD_MS);
  PORTB &= ~(0x20);
  vTaskDelay(250/portTICK_PERIOD_MS);
 }
}
void TaskRead(void *param){
  (void)param;
  int sensorvalue;
  pinMode(A0,INPUT);
  while(1){
    sensorvalue=analogRead(A0);
    xQueueSend(outputQueue,&sensorvalue,portMAX_DELAY);
  }
  vTaskDelay(10);
}

void TaskSerial(void *param){
  (void)param;
  Serial.begin(9600);
  int printOutput;
  while(!Serial){
    vTaskDelay(10);
  }
  while(1){
    if((xQueueReceive(outputQueue,&printOutput,portMAX_DELAY))==pdPASS){
      Serial.println(printOutput);
    }
    vTaskDelay(10);
  }
}
