#include <Arduino.h>
#include <FastLED.h>
#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BOUTON_ATOM_LIGHT 27
#define BOUTON_ATOM_BTN 39

  CRGB keyPixel;
  CRGB keyPixel2;

void setup() {
  
  // Initialiser FastLED pour contrôler le pixel RGB du M5Stack Key Unit
  FastLED.addLeds< WS2812, BROCHE_ATOM_FIL_JAUNE , GRB >(&keyPixel, 1); 
  FastLED.addLeds< WS2812, BOUTON_ATOM_LIGHT , GRB >(&keyPixel2, 1); 
  pinMode( BROCHE_ATOM_FIL_BLANC , INPUT_PULLUP );
  pinMode( BOUTON_ATOM_BTN , INPUT_PULLUP );

}

void loop() {
  int maLectureKey = digitalRead( BROCHE_ATOM_FIL_BLANC );
  int maLectureBouton = digitalRead(BOUTON_ATOM_BTN);
  if(maLectureKey==0){
  keyPixel = CRGB(255,255,0); // BLANC
  FastLED.show();
  }else{
    keyPixel = CRGB(0,0,0); // BLANC
    FastLED.show();
  }
  if(maLectureBouton==0){
    keyPixel2 = CRGB(255,255,0); // BLANC
    FastLED.show();
    }else{
      keyPixel2 = CRGB(0,0,0); // BLANC
      FastLED.show();
    }
delay(100);
}

