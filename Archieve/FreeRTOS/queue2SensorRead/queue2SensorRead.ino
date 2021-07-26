#include <Arduino_FreeRTOS.h>
#include <queue.h>

QueueHandle_t LDRQueue,POTQueue;
TaskHandle_t taskHand1,taskHand2,taskHand3;
void TaskLDR(void *param);
void TaskSerial(void *param);
void TaskPOT(void *param);
void setup() {
  // put your setup code here, to run once:
LDRQueue=xQueueCreate(10,sizeof(int));
POTQueue=xQueueCreate(10,sizeof(int));
if(LDRQueue!=NULL && POTQueue!=NULL){
xTaskCreate(
  TaskSerial,
  "PrintTask",
  128,
  NULL,
  2,
  &taskHand1
  );
xTaskCreate(
  TaskLDR,
  "AnalogReadLDR",
  128,
  NULL,
  1,
  &taskHand2
  );  
  xTaskCreate(
  TaskPOT,
  "POTTask",
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

void TaskLDR(void *param){
 (void)param;
 int LDRvalue;
 pinMode(A1,INPUT);
 while(1){
  LDRvalue=analogRead(A1);
  xQueueSend(LDRQueue,&LDRvalue,portMAX_DELAY);
 }
 vTaskDelay(10);
}
void TaskPOT(void *param){
  (void)param;
  int POTvalue;
  pinMode(A0,INPUT);
  while(1){
    POTvalue=analogRead(A0);
    xQueueSend(POTQueue,&POTvalue,portMAX_DELAY);
  }
  vTaskDelay(10);
}

void TaskSerial(void *param){
  (void)param;
  Serial.begin(9600);
  int POTOutput,LDROutput;
  while(!Serial){
    vTaskDelay(10);
  }
  while(1){
    if((xQueueReceive(POTQueue,&POTOutput,portMAX_DELAY))==pdPASS){
      Serial.println(POTOutput);
    }
    if((xQueueReceive(LDRQueue,&LDROutput,portMAX_DELAY))==pdPASS){
      Serial.print("LDR:");
      Serial.print(LDROutput);
      Serial.println(" ");
    }
    vTaskDelay(10);
  }
}
