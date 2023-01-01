#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void tick(bool emphasis) {
  drv.setWaveform(0, emphasis ? 17 : 22);
  drv.setWaveform(0, 1);
  drv.go();
}

void onNoteOn(byte channel, byte note, byte velocity) {
  tick(note == 69);
//  Serial.print("note: "); Serial.println(note);
}

void setup() {
//  Serial.begin(9600);
  usbMIDI.setHandleNoteOn(onNoteOn);
//  usbMIDI.setHandleNoteOff(onNoteOff);
  

//  usbMIDI.setHandleTimeCodeQuarterFrame(myTimeCodeQuarterFrame);
//  usbMIDI.setHandleClock(myClock);
//  usbMIDI.setHandleStart(myStart);
//  usbMIDI.setHandleContinue(myContinue);
//  usbMIDI.setHandleStop(myStop);

  drv.begin(); 
  drv.selectLibrary(1);
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG); 
}

void loop() {
  usbMIDI.read();
}
