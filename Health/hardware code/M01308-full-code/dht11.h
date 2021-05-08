#ifndef DHT11_H
#define DHT11_H
#include"Arduino.h"
class DHT {
  public:
    void dht_read(int _pin);
    unsigned char temperature, RH ;
    unsigned volatile int dht_pin;
  private:
    char read_dht11();
    void begin();
    void find_response();
    unsigned char Check_bit, Temp_byte_1,Temp_byte_2,RH_byte_1,RH_byte_2,Sumation;
};


#endif
