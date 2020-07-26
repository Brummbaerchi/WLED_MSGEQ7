#define MSGEQ7_10BIT              //Use all 10 Bits of the ESP8266's ADC, ESP32 supports 12 Bit (but not the MSGEQ7 lib)
#include "MSGEQ7.h"               //https://github.com/NicoHood/MSGEQ7

#ifdef ESP8266
  #define pinAnalog A0
#else 
  #define pinAnalog 36
#endif
#define pinReset 5
#define pinStrobe 4
#define MSGEQ7_SMOOTH 0


CMSGEQ7<MSGEQ7_SMOOTH, pinReset, pinStrobe, pinAnalog> MSGEQ7;

uint16_t musicValue = 0;
uint16_t mappedValue[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t filterValue[8] = {112, 125, 182, 150, 130, 135, 153, 150};    //Set this as you need, it may vary depending on your setup

uint8_t myVals[32];       //To allow a FX Effect to work, copied from atuline
bool samplePeak;

long lastTime = 0;          //Stolen from Atuline to avoid wled overload
int delayMs = 15;           //~67x per second should be sufficient

void initAudio() {
  MSGEQ7.begin();
}

void refreshAudio() {
  MSGEQ7.read();                                      //Tells the IC to read Data
  musicValue = MSGEQ7.getVolume();                                //Returns the average Volume among all frequency bands
  musicValue = constrain(musicValue, filterValue[7], 1024);                 //Limit musicValue to avoid underflow
  mappedValue[7] = map(musicValue, filterValue[7], 1024, 0, 1024);
  
  for(int i = 0; i < 7;i++) {
    musicValue = MSGEQ7.get(i);                          //Select the above chosen frequency and save it
    musicValue = constrain(musicValue, filterValue[i], 1024);                 //Limit musicValue to avoid underflow
    mappedValue[i] = map(musicValue, filterValue[i], 1024, 0, 1024);
  }
}
