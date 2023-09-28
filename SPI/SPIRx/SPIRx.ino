# include <SPI.h>
char str[4];
volatile int i;
volatile bool pin;
volatile char databyte;

void setup()
 {
  Serial.begin (115200);   // set baud rate to 115200 for usart
  Serial.println("Hello I'm SPI UNO_SLAVE");
  // pinMode(13, OUTPUT);
  pinMode(MISO, OUTPUT); // have to send on Master in so it set as output
  SPCR |= _BV(SPE); // turn on SPI in slave mode
  i = 0; // buffer empty
  pin = false;
  SPI.attachInterrupt();     // turn on interrupt
}

void loop(){
  // static int count;
  // if (pin)
  // {
  //   pin = false;   //reset the pin
  //   if(count++< 3){
  //   Serial.print(count);
  //   Serial.print(" : ");
  if ((databyte == '1') || (databyte == '0'))
  {
    Serial.println(databyte); //print the array on serial monitor
    // LED OUTPUT wont work here because 13 is used as SCK
    // if(databyte == '1')
    // {
    //   digitalWrite(13,HIGH);
    //   delay(1000);
    //   digitalWrite(13,LOW);
    //   delay(1000);
    // }
    // else
    // {
    //   digitalWrite(13,LOW);
    //   delay(100);
    // }
    databyte = 2;
  }
  delay(1000);
//     if(count==5)
//     {
//       delay(1000);
//       Serial.println("The end data");
//     }
//     delay(1000);
//     i= 0; //reset button to zero
//   }
// }
}

// Interrupt function
ISR (SPI_STC_vect) 
{
  databyte = SPDR;        // read byte from SPI Data Register
  // str[i++] = c;
  // if (i < sizeof(str)) {
  //   str [i++] = c; // save data in the next index in the array buff
  // //   if ( (c == '\r') || (c == '\n') || (c=='\0') ) //check for the end of the word
  //     pin = true;
  // }
}