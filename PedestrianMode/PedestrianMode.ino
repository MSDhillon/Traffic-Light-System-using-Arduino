// C++ code
//
float distance;

float readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int counter;

void setup()
{
  Serial.begin(9600);

  pinMode(10, OUTPUT); // Define PIN 10 as an OUTPUT
  pinMode(9, OUTPUT); // Define PIN 9 as an OUTPUT
  pinMode(11, OUTPUT); // Define PIN 11 as an OUTPUT
  pinMode(2, OUTPUT); // Define PIN 2 as an OUTPUT
}

void loop()
{
  digitalWrite(9, HIGH); // Turn on LED connected to PIN 9
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(9, LOW); // Turn off LED connected to PIN 9
  delay(1000); // Wait for 1000 millisecond(s)
  calculateDistance(); // Calling an external function
     
  digitalWrite(10, HIGH); // Turn on LED connected to PIN 10
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW); // Turn off LED connected to PIN 10
  delay(1000); // Wait for 1000 millisecond(s)
  calculateDistance();
    
  digitalWrite(11, HIGH); // Turn on LED connected to PIN 11
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW); // Turn off LED connected to PIN 11
  delay(1000); // Wait for 1000 millisecond(s)
  calculateDistance();
    
  digitalWrite(10, HIGH); // Turn on LED connected to PIN 10
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(10, LOW); // Turn off LED connected to PIN 10
  delay(1000); // Wait for 1000 millisecond(s)
  calculateDistance();
}

void calculateDistance(){
  distance = 0.01723 * readUltrasonicDistance(13, 12); // Calculating the distance
  Serial.println(distance); // Printing the distance
  if (distance < 10) {
    for (counter = 0; counter < 10; ++counter) { // Function to blink Yellow LED 10 times
      digitalWrite(10, HIGH);
      tone(2, 200, 100); // Playing the buzzer while LED is blinking
      delay(100);
      digitalWrite(10, LOW);
      delay(100);
    }
  }
}
