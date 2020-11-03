#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t xSerialSemaphore; //As two function access a single resource at same time we create semaphore to share between them
void Task1(void *param);
void Task2(void *param);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
while (!Serial){}
if(xSerialSemaphore==NULL){
 xSerialSemaphore=xSemaphoreCreateMutex(); //create mutex to share the resource
  if((xSerialSemaphore)!=NULL){
    xSemaphoreGive((xSerialSemaphore));//Free or Give port to others
  }
}

xTaskCreate(
  Task1, //Task function
  "Task1",//human readable
  100,//stack size
  NULL,//arguments
  2,//priority
  NULL//handler
  );

xTaskCreate(
  Task2, 
  "Task2",
  100,
  NULL,
  2,
  NULL
  );
}

void loop() {
  // put your main code here, to run repeatedly:
//Do nothing
}

void Task1(void *param){
  (void)param;
  while(1){
    if(xSemaphoreTake(xSerialSemaphore,(TickType_t)5)== pdTRUE){//Take resource else wait for 5xTickType
    Serial.println("1.Task1");
    xSemaphoreGive(xSerialSemaphore);//free the resource
    }
    vTaskDelay(100);
    }
  }

void Task2(void *param){
  (void)param;
  while(1){
    if(xSemaphoreTake(xSerialSemaphore,(TickType_t)5)== pdTRUE){
    Serial.println("2.***Task2***");
    xSemaphoreGive(xSerialSemaphore);
    }
    vTaskDelay(100);
    }
  }
