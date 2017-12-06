const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int photocell = 0;                // the photocell

int photocellPin = A3;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int light = 5;

//Create variables for timer
long prev_time = 0;
long diff_time = 0;  
long prev_time2 = 0;
long diff_time2 = 0;  
//Creates varaible that defines blink rate Time is in Milliseconds 1sec = 1000ms 
const long interval = 600;

 boolean setupFlag = true;

int photocellLast = 0;

void setup(void) {
  // We'll send debugging information via the Serial monitor

  pinMode(light, OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }


}
 
void loop(void) {
  
if(setupFlag == true){
  digitalWrite(light,HIGH);
 }
  
if( diff_time > 50 && setupFlag == true){
  setupFlag = false;
  digitalWrite(light,LOW);
}

 

digitalWrite(6,HIGH);
smoothing();
//starts timer & checks time at the start of the loop
long curr_time = millis();
//Checks to see how much time has passed
diff_time = (curr_time - prev_time);

int flip = (photocellLast - photocell);
//Serial.println(photocell);
//Checks to see if enough time has passed based on the interval
if(diff_time >= interval){
  photocellLast = photocell;
  //sets current time to be the previous time
  prev_time = curr_time;
  if(flip > 10){
    boolean flag = true;

//Checks to see how much time has passed


    while (flag == true){
      long curr_time2 = millis();
      diff_time2 = (curr_time2 - prev_time2);
      digitalWrite(light,HIGH);

      if(diff_time2 >=5000){
        digitalWrite(light,LOW);
        prev_time2 = curr_time2;
        flag = false;
      }
        
    }


 

}}}

void smoothing(){
   // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  Serial.println( analogRead(photocellPin));
  readings[readIndex] = analogRead(photocellPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the photocell:
  photocell = total / numReadings;
  // send it to the computer as ASCII digits
  //Serial.println("photocell =");
  //Serial.println(photocell);
  delay(1);        // delay in between reads for stability
}


