#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN D1
#define PIN2 D2
#define NUMPIXELS      30

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Servo myservo;
int pos = 0;
 
const char* ssid = "Troy and Abed in the Modem";
const char* password = "Zinger1234";
 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  myservo.attach(D2);
 myservo.write(90);
pixels.begin();
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
  
  for(int i=0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i, pixels.Color(195,0,182));
  pixels.show();
  delay(25);
  }

    myservo.write(92);              // tell servo to go to position in variable 'pos'

    
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
      for(int i=0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i, pixels.Color(0,0,0));
  pixels.show();
  delay(25);
  }
 myservo.write(89);
 }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");
  client.println("<a href=\"/LED=ON\"\"><textbox></textbox></a><br />");
 
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

 }

