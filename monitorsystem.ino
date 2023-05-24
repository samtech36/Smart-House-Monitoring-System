#define NOTE_C5 523
// Define connection pins:
#define pirPin 6 //set the motion detector pin to 6
#define echoPin 13 //set the echo pin for the ultrasonic sensor pin to 13
#define trigPin 12 //set the echo pin for the ultrasonic sensor pin to 12
// Create variables:
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int red_light_pin = 2; //set the red LED pin to 2
int green_light_pin = 4; //set the red green pin to 4
int blue_light_pin = 3; //set the blue LED pin to 3
int Buzz = 8; //set the buzzer pin to 8
int val = 0;
bool motionState = false; // We start with no motion detected.
void setup()
{
 // Configure the pins as input or output:
 pinMode(pirPin, INPUT);
 pinMode(red_light_pin, OUTPUT);
 pinMode(green_light_pin, OUTPUT);
 pinMode(blue_light_pin, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 // Begin serial communication at a baud rate of 9600:
 Serial.begin(9600);// Serial Communication
}
void loop()
{
 // Read out the pirPin and store as val:
 val = digitalRead(pirPin);
 // If motion is detected (pirPin = HIGH), do the following:
 if (val == HIGH)
 {

 //if distance is between 50 to 100 cm run the code below
 if (distance > 50 && distance < 100)
 {
 RGB_color(255, 255, 255); // White
 delay(1000);
 RGB_color(0, 0, 0); // no color
 delay(1000);
 }
 //if distance is below 50 cm run the code below
 if (distance < 50)
 {
 tone(Buzz, NOTE_C5, 2000); // Play note C5 (alarm)
 RGB_color(255, 0, 0); // Red
 delay(500);
 RGB_color(0, 0, 255); // Blue
 delay(500);

 }
 //if distance is greater then 100 cm run the code below
 else (distance > 100);
 {
 RGB_color(0, 0, 0); // LED Turns off
 delay(1000);
 }
 //print Motion Detected in serial monitor when motion sensor detects
motion
 if (motionState == false)
 {
 Serial.println("Motion detected!");
 motionState = true;
 }
 }
 // If no motion is detected (pirPin = LOW), do the following:
 else
 {
 // Change the motion state to false (no motion):
 if (motionState == true)
 {
 Serial.println("Motion ended!");
 motionState = false;

 }
 }
 // Clears the trigPin condition
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds
 duration = pulseIn(echoPin, HIGH);
 // Calculating the distance
 distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go
and back)
 // Displays the distance on the Serial Monitor
 Serial.print("Distance: ");
 Serial.print(distance);
 Serial.println(" cm");
 delay(2000);
}
//set each pin color to a color value
void RGB_color(int red_light_value, int green_light_value, int
blue_light_value)
{
 analogWrite(red_light_pin, red_light_value);
 analogWrite(green_light_pin, green_light_value);
 analogWrite(blue_light_pin, blue_light_value);
}
