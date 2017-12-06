//RGB LED by Aaron Landtree 9/10/2017
//no copyright
//Reuse, recycle, cut-up, chop, use as you see fit.
//www.aarondelanty.com
//Find more code examples:
//https://github.com/landtree

//sets LED colors to PWM(~) pins 9,10,11
const int green = 11;
const int blue = 10;
const int red = 9;

//creates varibles used for values for LED colors
int gval = 0;
int bval = 0;
int rval = 0;

void setup() {
//Turns LED pins to output
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
pinMode(red, OUTPUT);

}

void loop() {
  analogWrite(blue, 100);

  for(rval =60; rval <=254; rval++){
  analogWrite(red, rval);
  delay(5);
  }
  for(rval = 255; rval >=60; rval = (rval - 5)){
  analogWrite(red, rval);
  delay(5);
  }
  
  for(gval = 0; gval <=254; gval++){
  analogWrite(green, gval);
  delay(5);
  }
  for(gval = 255; gval >=0; gval = (gval - 1)){
  analogWrite(green, gval);
  delay(5);
  }

 

}
