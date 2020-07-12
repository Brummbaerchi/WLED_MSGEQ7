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

int filter = 115;           //Set this as you need, it may vary depending on your setup
uint16_t musicValue = 0;
uint16_t musicValue_test = 0;
uint16_t mappedValue = 0;

uint8_t myVals[32];       //To allow a FX Effect to work, copied from atuline
bool samplePeak;

int selectedFreq = 0;       //63Hz

long lastTime = 0;          //Stolen from Atuline to avoid wled overload
int delayMs = 15;           //~67x per second should be sufficient

void initAudio() {
  MSGEQ7.begin();
}

void refreshAudio() {
  MSGEQ7.read();                                                    //Tells the IC to read Data
  if(selectedFreq == 7) {		//Overall Volume
    musicValue = MSGEQ7.getVolume();                                //Returns the average Volume among all frequency bands
  }
  else { // 0-6: Frequency Bands
    musicValue = MSGEQ7.get(selectedFreq);                          //Select the above chosen frequency and save it
  }
  musicValue = constrain(musicValue, filter, 1024);                 //Limit musicValue to avoid underflow
  mappedValue = map(musicValue, filter, 1024, 0, 1024);             //Remove noise
  
}
