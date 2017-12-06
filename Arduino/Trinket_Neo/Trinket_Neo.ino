#include <Adafruit_NeoPixel.h>


//defines Neopixels
#define PIN           8
#define NUMPIXELS      12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

for(int i = 0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i, pixels.Color(200,20,240));
   pixels.show();
   delay(50);
}
for(int i = 0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i, pixels.Color(50,20,240));
   pixels.show();
   delay(50);
}}

