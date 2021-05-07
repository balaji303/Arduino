#include"dht11.h"

void DHT:: dht_read(int _pin)
{
  dht_pin = _pin;
  begin();
  find_response();
  if (Check_bit == 1)
  {
    RH_byte_1 = read_dht11();
    RH_byte_2 = read_dht11();
    Temp_byte_1 = read_dht11();
    Temp_byte_2 = read_dht11();
    Sumation = read_dht11();
    if (Sumation == ((RH_byte_1 + RH_byte_2 + Temp_byte_1 + Temp_byte_2) & 0XFF))
    {
      temperature = Temp_byte_1;
      RH = RH_byte_1;
      // Serial.println(temperature);
      //Serial.println(RH);
    }
    else {
      Serial.println("Check sum error");
    }
  }
  else
  {
    Serial.println("No Response.");
  }
}
void DHT::begin()
{
  pinMode(dht_pin, OUTPUT);
  digitalWrite(dht_pin, LOW);
  delay(18);
  digitalWrite(dht_pin, HIGH);
  delayMicroseconds(20);
  pinMode(dht_pin, INPUT_PULLUP);
}
void DHT::find_response() {
  Check_bit = 0;
  delayMicroseconds(40);
  if (digitalRead(dht_pin) == 0) {
    delayMicroseconds(80);
    if (digitalRead(dht_pin) == 1) {
      Check_bit = 1;
    }
    delayMicroseconds(50);
  }
}

char DHT:: read_dht11() {
  char data, for_count;
  for (for_count = 0; for_count < 8; for_count++)
  {
    while (digitalRead(dht_pin) == 0);
    delayMicroseconds(30);
    if (digitalRead(dht_pin) == 0) {
      data &= ~(1 << (7 - for_count)); //Clear bit (7-b)
    }
    else {
      data |= (1 << (7 - for_count)); //Set bit (7-b)
      while (digitalRead(dht_pin));
    }
  }
  return data;
}
