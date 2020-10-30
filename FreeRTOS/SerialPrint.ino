//Print 2 Name at Same time
#include <Arduino_FreeRTOS.h>

void TaskName1(void *param); //Task name and parameter 
void TaskName2(void *param); //Task name and parameter
TaskHandle_t TaskHandle1;    //TaskHandler's name
TaskHandle_t TaskHandle2;    //TaskHandler's name
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);          //Buad Rate
 
xTaskCreate(                 //Create a Task
    TaskName1,               //Task's Function
    "Task1",                 //Name for that Task
    100,                     //Stack Size
    NULL,                    //Parameters
    1,                       //Priority
    &TaskHandle1              //Address of Task Handler
    );


xTaskCreate(                 //Create a Task
    TaskName2,               //Task's Function
    "Task1",                 //Name for that Task
    100,                     //Stack Size
    NULL,                    //Parameters
    3,                       //Priority
    &TaskHandle1              //Address of Task Handler
    );
}

void loop() {
  // put your main code here, to run repeatedly:
//Don't write anything in Code
}

void TaskName1(void *param){
   (void) param; //No parameter
   while(1){ //Never Ending Loop
    Serial.println("1.Balaji");
    vTaskDelay(1000/portTICK_PERIOD_MS); //Delay function in FreeRTOS
   }
}

void TaskName2(void *param){
   (void) param;
   while(1){
    Serial.println("2.Balaji303");
    vTaskDelay(1000/portTICK_PERIOD_MS);
   }
}
