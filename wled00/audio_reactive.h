#define MSGEQ7_10BIT
#include "MSGEQ7.h"               //https://github.com/NicoHood/MSGEQ7
#define pinAnalog A0
#define pinReset 5
#define pinStrobe 4
#define MSGEQ7_SMOOTH 0


CMSGEQ7<MSGEQ7_SMOOTH, pinReset, pinStrobe, pinAnalog> MSGEQ7;

int filter = 115;           //Set this as you need, it may vary depending on your setup
uint16_t musicValue = 0;
uint16_t mappedValue = 0;

int selectedFreq = 0;       //63Hz

long lastTime = 0;          //Stolen from Atuline to avoid wled overload
int delayMs = 10;           //50x per second should be sufficient

void initAudio() {
  MSGEQ7.begin();
}

void refreshAudio() {
  MSGEQ7.read();                              //Tells the IC to read Data
  musicValue = MSGEQ7.get(selectedFreq);  //Select the above chosen frequency and save it
  musicValue = constrain(musicValue, filter, 1024);                 //Limit musicValue to avoid underflow
  mappedValue = map(musicValue, filter, 1024, 0, 1024);        //Remove noise
}
