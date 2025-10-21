#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>

MicroOscSlip<128> monOsc(&Serial);

#define BOUTON_ATOM_BTN 39
#include <M5_PbHub.h>
#define KEY_CHANNEL 0

M5_PbHub myPbHub;


void setup()
{
  Serial.begin(115200);
  Wire.begin();
  myPbHub.begin();

  pinMode(BOUTON_ATOM_BTN, INPUT_PULLUP);
}

void loop()
{
  int value = myPbHub.digitalRead(KEY_CHANNEL);


  monOsc.sendInt("/bouton", value);

  
  delay(100);
}
