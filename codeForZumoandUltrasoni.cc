// defines pins numbers
const int servo = 9;
const int trigPin = 10;
const int echoPin = 11;

// defines variables
long duration;
int distance;
int light;
long r, g, b;

#include <Servo.h>
#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    30
CRGB leds[NUM_LEDS];

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(5, OUTPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);   // Sets Servo to initially 0 degrees
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  for (int i = 0; i <= 29; i++) {



    leds[i] = CRGB(255, 0, 0);              // turn on strip red
    FastLED.show();
    delay(10);

  }
  //
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  //Servo
  if (distance < 7) { //Check distance is less than 10cm
    for (int i = 0; i <= 29; i++) {
      leds[i] = CRGB(0, 255, 0);              // turn on strip green
      FastLED.show();
      delay(10);
    }
    myservo.write(45); // Sets Servo in stages from 0 to 180 degrees so soap does not pitch out.
    delay(100);
    myservo.write(90);
    delay(100);
    myservo.write(135);
    delay(100);
    myservo.write(180); //Ajust how far you want the servo to go.
    delay(1000);
    myservo.write(0); // Reset the servo to 0 Degrees
    delay(3000);   //Delay the next time someone can get soap
  }
}
