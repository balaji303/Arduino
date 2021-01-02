/*
 * Example of a basic FreeRTOS queue
 * https://www.freertos.org/Embedded-RTOS-Queues.html
 */

// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>

// Include queue support
#include <queue.h>

struct Arduino{
  int pin[3];
  int ReadValue1;
  int ReadValue2;
};

void Blink(void *param);
void POT1(void *param);
void POT2(void *param);
void PrintSerial(void *param);
QueueHandle_t structArrayQueue;
void setup() {
  // put your setup code here, to run once:
structArrayQueue=xQueueCreate(10,sizeof(struct Arduino));
if(structArrayQueue!=NULL){
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
  pinMode(A0,INPUT);
  while(1){
  struct Arduino var;
  var.pin[0]=0;
  var.ReadValue1=analogRead(A0);
  
  xQueueSend(structArrayQueue,&var,portMAX_DELAY);
  vTaskDelay(1);
  }
}

void POT2(void *param){
  (void) param;
  pinMode(A1,INPUT);
  while(1){
  struct Arduino var;
  var.pin[1]=1;
  var.ReadValue2=analogRead(A1);
  
  xQueueSend(structArrayQueue,&var,portMAX_DELAY);
  vTaskDelay(1);
  }
}

void PrintSerial(void *param){
  (void) param;
  Serial.begin(9600);
  while(1){
    struct Arduino var;
    if(xQueueReceive(structArrayQueue,&var,portMAX_DELAY) == pdPASS ){
      Serial.print("PIN:");
      Serial.println(var.pin[1]);
      Serial.print("value:");
      Serial.println(var.ReadValue1);
      Serial.print("PIN:");
      Serial.println("1");
      Serial.print("value:");
      Serial.println(var.ReadValue2);
    }
//   }
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}
