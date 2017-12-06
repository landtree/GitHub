
// Detect the falling edge

// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce-Arduino-Wiring
#include <Bounce2.h>
#include <Adafruit_NeoPixel.h>

#define button 10
#define PIN           14
#define NUMPIXELS     41

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int cnt = 0;

// Instantiate a Bounce object :
Bounce debouncer = Bounce(); 

void setup() {
  
  // Setup the button with an internal pull-up :
  pinMode(button,HIGH);
 
  // After setting up the button, setup the Bounce instance :
  debouncer.attach(button);
  debouncer.interval(10);
  Serial.begin(9600);
  pixels.begin();
}

void loop() {

  // Update the Bounce instance :
   debouncer.update();
   Serial.println(cnt);
   // Call code if Bounce fell (transition from HIGH to LOW) :
   if ( debouncer.fell() ) {
    cnt++;

    if (cnt > 6) {
        cnt = 1;  
        }

     switch (cnt) {

  case 1:
for(int i = 0;i<NUMPIXELS; i = (i + 3)){
  pixels.setPixelColor(i, pixels.Color(1,120,100));
   pixels.show();
   delay(50);
}
    break;
  case 2:
for(int i = 0;i<NUMPIXELS; i = (i + 2)){
  pixels.setPixelColor(i, pixels.Color(100,20,50));
   pixels.show();
   delay(50);
}
    break;
  case 3:
  
for(int i = 1;i<NUMPIXELS; i = (i + 2)){
  pixels.setPixelColor(i, pixels.Color(50,200,255));
   pixels.show();
   delay(50);
}
    break;
      case 4:
  
for(int i = 0;i<NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(6,27,99));
   pixels.show();
   delay(50);
}
    break;
    
case 5:
while (cnt == 5){ 
     if ( debouncer.fell() ) {
    cnt++;
     } 
for(int i = 0;i<NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(75,75,75));
   pixels.show();
   delay(40);
}
for(int i = 0;i<NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(25,50,10));
   pixels.show();
   delay(80);
}
for(int i = 0;i<NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(15,100,20));
   pixels.show();
   delay(25);
}
}
    break;
    
   case 6:
  
for(int i = 0;i<NUMPIXELS; i++){
  pixels.setPixelColor(i, pixels.Color(0,0,0));
   pixels.show();
   delay(50);
}
    break;
}   
   }
}

