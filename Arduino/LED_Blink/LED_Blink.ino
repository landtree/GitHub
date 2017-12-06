//Blink LED by Aaron Landtree 9/10/2017
//no copyright
//Reuse, recycle, cut-up, chop, use as you see fit.
//www.aarondelanty.com
//Find more code examples:
//https://github.com/landtree

//sets LED to pin 11
const int LED = 11;
//Creates ON/OFF outputs
const boolean ON = HIGH;
const boolean OFF = LOW;
//Create variables for timer
long prev_time = 0;
long diff_time = 0;  
//Creates varaible that defines blink rate Time is in Milliseconds 1sec = 1000ms 
const long interval = 600;

//Startup code that runs once when the Arduino starts
void setup() {
//Sets pin 11(LED) to be an output
pinMode(LED, OUTPUT);
//sets LED to start in an off position
digitalWrite(LED,OFF);
}

void loop() {
//starts timer & checks time at the start of the loop
long curr_time = millis();

//Checks to see how much time has passed
diff_time = (curr_time - prev_time);

//Checks to see if enough time has passed based on the interval
if(diff_time >= interval){
  //sets current time to be the previous time
  prev_time = curr_time;
  //Turns on the LED
  digitalWrite(LED, ON);  
  }
else{
  //Turns off the LED
  digitalWrite(LED, OFF);
}
  
}

