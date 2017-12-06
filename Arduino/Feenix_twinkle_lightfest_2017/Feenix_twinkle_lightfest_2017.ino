#include <Adafruit_NeoPixel.h>


//defines Neopixels
#define PIN           7
#define NUMPIXELS      149

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  int  i = random(0,NUMPIXELS);
  
   pixels.setPixelColor(i, pixels.Color(200,200,255));
   pixels.setPixelColor(i+1, pixels.Color(0,200/8,255/8));
   pixels.setPixelColor(i-1, pixels.Color(0,200/8,255/8));
   pixels.show();
   delay(10);
   pixels.setPixelColor(i, pixels.Color(0,0,0));
   pixels.setPixelColor(i+1, pixels.Color(0,0,0));
   pixels.setPixelColor(i-1, pixels.Color(0,0,0));
   delay(125);
}

