#include <Arduino_FreeRTOS.h>
const bool valueToAssert=true;
void setup() {
  // put your setup code here, to run once:
// Assert value is true, execution doesn't stop.  
configASSERT(valueToAssert==true);
// Assert value is false, FreeRTOS execution stops and start to blink main led two times with 4 second cycle.
configASSERT(valueToAssert==false);
}

void loop() {
  // put your main code here, to run repeatedly:

}
