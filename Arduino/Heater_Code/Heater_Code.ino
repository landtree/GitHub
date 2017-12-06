// constants won't change. Used here to 
// set pin numbers:
const int HeatPin =  13;      // the number of the LED pin
 
// Variables will change:
int HeatState = LOW;             // HeatState used to set the heater
long previousMillis = 0;        // will store last time heater was updated
long interval = 1000;           // interval at which to be on for
 
void setup() {
  // set the digital pin as output:
  pinMode(HeatPin, OUTPUT);      
}
 
void loop(){
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you started heater  
    previousMillis = currentMillis;   
     // if the Heater is off turn it on and vice-versa:
    if (HeatState == LOW)
      HeatState = HIGH;
    else
      HeatState = LOW;
 
    // set the Heater with the ledState of the variable:
    digitalWrite(HeatPin, HeatState);
  }
}
