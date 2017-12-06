//defines heater to a PWM pin
#define heater         10

//Sets on/off values
boolean on = 1;
boolean off = 0;

//defines thermistor pin and math varables to calculate temperture
int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

//creates timer value
long previousMillis = 0;        // will store last time heater was updated
long timer = 1000;           // interval at which to be on for

void setup() {
//turns on communication debugging
Serial.begin(9600);

//sets the heater pin to be output
pinMode(heater, OUTPUT);
//starts the neopixels

}

void loop() {

  
//starts timing here  
unsigned long currentMillis = millis();

 if(currentMillis - previousMillis > timer) { 
  
  //resets the timer
  previousMillis = currentMillis;
  
  //Reads the thermistor and calculates to find temperature in F
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 
 }
  //Prints the temperature to console
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" F"); 
 
  if (T < 90 || T >= 99){
    Serial.println("Heater is currently on");
    //turns the heater on
    digitalWrite(heater, on);
  }
  else{
    Serial.println("Heater is currently off");
    digitalWrite(heater, off);
  }
 
}

