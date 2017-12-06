//Adafruit library for Neopixels
#include <Adafruit_NeoPixel.h>

//Neopixel varibles for Data pin(DIN) and the amount of LEDs connected
#define PIN           12
#define NUMPIXELS     1

//defines pixels color setup and pins/pixels 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//defines motor to a PWM pin
#define motor         10

//defines thermistor pin and math varables to calculate temperture
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
//turns on communication debugging
Serial.begin(9600);

//sets the motor pin to be output
pinMode(motor, OUTPUT);
//starts the neopixels
pixels.begin();
}

void loop() {

  //Reads the thermistor and calculates to find temperature in F
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 

  //Prints the temperature to console
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" F"); 

  //creates a mapping function to control the motor speed
  //Uses the T(temperture) between 50-100 degress to control the speed between 0-255
  int  motorSpeed = map(T, 50, 100, 0, 255);

  //This prevents the map function going over 255(max PWM)
  if (motorSpeed >= 255){
      motorSpeed = 255;    
  }
  
  //creates a mapping function to control the value of the color red
  //Uses the T(temperture) between 50-100 degress to control the brightness between 0-255
  int  red = map(T, 50, 100, 10, 200);

  //This prevents the map function going over 255(max PWM)
  if (red >= 255){
      red = 255;    
  }  
  
  //prints the speed of the motor
  Serial.println(motorSpeed);

  //writes to the motor pin at the mapped speed
  analogWrite(motor, motorSpeed);

  //sets the pixel color of the 1 LED(0) and sets the color to be blue
  //and mix in the red at the rate of the temperture 
  pixels.setPixelColor(0, pixels.Color(red,20,100));
  pixels.show(); 

}

