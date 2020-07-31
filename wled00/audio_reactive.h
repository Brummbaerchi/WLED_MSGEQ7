#define MSGEQ7_10BIT              //Use all 10 Bits of the ESP8266's ADC, ESP32 supports 12 Bit (but not the MSGEQ7 lib)
#include "MSGEQ7.h"               //https://github.com/NicoHood/MSGEQ7

#ifdef ESP8266
  #define pinAnalog A0
#else 
  #define pinAnalog 36
#endif
#define pinReset 5
#define pinStrobe 4
#define MSGEQ7_SMOOTH 0           //Has to be zero, because of https://github.com/NicoHood/MSGEQ7/issues/14


CMSGEQ7<MSGEQ7_SMOOTH, pinReset, pinStrobe, pinAnalog> MSGEQ7;

uint16_t musicValue = 0;
uint16_t mappedValue[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t filterValue[8] = {213, 255, 250, 233, 220, 230, 231, 253};    //Set this as you need, it may vary depending on your setup
//mappedValue and filterValue array: index 0-6 frequency bands, 7: overall volume
uint8_t maxfilterValue[8] = {0, 0, 0, 0, 0, 0, 0, 0};

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
  

  //Uncomment this (but comment the top section in exchange) to get your filter values printed
  
  /*MSGEQ7.read();                                      //Tells the IC to read Data
  musicValue = MSGEQ7.getVolume();                                //Returns the average Volume among all frequency bands
  if(musicValue > maxfilterValue[7]) {
    maxfilterValue[7] = musicValue;
  }
  musicValue = constrain(musicValue, filterValue[7], 1024);                 //Limit musicValue to avoid underflow
  mappedValue[7] = map(musicValue, filterValue[7], 1024, 0, 1024);
  
  for(int i = 0; i < 7;i++) {
    musicValue = MSGEQ7.get(i);                          //Select the above chosen frequency and save it
    if(musicValue > maxfilterValue[i]) {
      maxfilterValue[i] = musicValue;
    }
    musicValue = constrain(musicValue, filterValue[i], 1024);                 //Limit musicValue to avoid underflow
    mappedValue[i] = map(musicValue, filterValue[i], 1024, 0, 1024);
    Serial.print(maxfilterValue[i]);
    Serial.print("\t");
  }
  Serial.print(maxfilterValue[7]);
  Serial.println();
  
  if (Serial.available() > 0) {
    for(int i = 0; i < 8;i++) {
      maxfilterValue[i] = 0;
    }
    Serial.read();
  }*/
}
