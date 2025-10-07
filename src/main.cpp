#include <Arduino.h>
#include <FastLED.h>
#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BOUTON_ATOM_LIGHT 27
#define BOUTON_ATOM_BTN 39
#include <M5_PbHub.h>
#define KEY_CHANNEL 0

M5_PbHub myPbHub;
CRGB keyPixel;
CRGB keyPixel2;

void setup()
{
  Wire.begin();
  myPbHub.begin();

  // Initialiser FastLED pour contrôler le pixel RGB du M5Stack Key Unit
  // FastLED.addLeds<WS2812, BROCHE_ATOM_FIL_JAUNE, GRB>(&keyPixel, 1);
  FastLED.addLeds<WS2812, BOUTON_ATOM_LIGHT, GRB>(&keyPixel2, 1);
  myPbHub.setPixelCount( KEY_CHANNEL ,  1 );

  // pinMode(BROCHE_ATOM_FIL_BLANC, INPUT_PULLUP);
  pinMode(BOUTON_ATOM_BTN, INPUT_PULLUP);
}

void loop()
{
  int value = myPbHub.digitalRead(KEY_CHANNEL);

  int maLectureKey = digitalRead(BROCHE_ATOM_FIL_BLANC);
  int maLectureBouton = digitalRead(BOUTON_ATOM_BTN);
   if (value == 0)
  {
    myPbHub.setPixelColor(KEY_CHANNEL, 0, 127,255, 0);
    
   }
   else
   {
    myPbHub.setPixelColor(KEY_CHANNEL, 0, 0,0, 0);
     
  }


  if (maLectureBouton == 0)
  {
    keyPixel2 = CRGB(255, 255, 0); // BLANC
    
  }
  else
  {
    keyPixel2 = CRGB(0, 0, 0); // BLANC
   
  }
  FastLED.show();
  delay(100);
}
