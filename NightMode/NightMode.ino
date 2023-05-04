// C++ code
//
float distance; // Declare a variable that can have a decimal place

float readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  // Set the trigger pin to LOW state for 10 microseconds
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  //Sets the trigger pin to LOW state
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int counter; // Variable to perform a loop
int buttonState = 0; // Variable to read button status

void setup()
{
  Serial.begin(9600);

  pinMode(10, OUTPUT); // Yellow LED
  pinMode(9, OUTPUT); // Red LED
  pinMode(11, OUTPUT); // Green LED
  pinMode(2, OUTPUT); // Buzzer
  pinMode(3, INPUT); // Button
}

void loop()
{ 
  calculateLight(); // Calling an external function
  
  digitalWrite(9, HIGH); // Turn on LED connected to PIN 9
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(9, LOW); // Turn off LED connected to PIN 9
  delay(1000); // Wait for 1000 millisecond(s)
  
  pushButton(); // Calling an external function
  calculateDistance(); // Calling an external function
  calculateLight(); // Calling an external function
     
  digitalWrite(10, HIGH); // Turn on LED connected to PIN 10
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW); // Turn off LED connected to PIN 10
  delay(1000); // Wait for 1000 millisecond(s)
  
  calculateDistance(); // Calling an external function
  calculateLight(); // Calling an external function
    
  digitalWrite(11, HIGH); // Turn on LED connected to PIN 11
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW); // Turn off LED connected to PIN 11
  delay(1000); // Wait for 1000 millisecond(s)
  
  calculateDistance(); // Calling an external function
  calculateLight(); // Calling an external function
    
  digitalWrite(10, HIGH); // Turn on LED connected to PIN 10
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(10, LOW); // Turn off LED connected to PIN 10
  delay(1000); // Wait for 1000 millisecond(s)
  
  pushButton(); // Calling an external function
  calculateDistance(); // Calling an external function
  calculateLight(); // Calling an external function
}

void calculateDistance() {
  distance = 0.01723 * readUltrasonicDistance(13, 12); // Calculating the distance
  Serial.print("Distance: "); // Printing the distance
  Serial.println(distance);
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

int light;

void calculateLight() {
  light = analogRead(A0); // Read light level from A0
  Serial.print("Light: ");
  Serial.println(light); // Print Light value
  while (light < 500) { // Loop until light is under 500
    digitalWrite(9, HIGH);
    light = analogRead(A0);
    distance = 0.01723 * readUltrasonicDistance(13, 12);
    if (distance <= 20) { // If the distance is within 20 run function
      digitalWrite(9, LOW);
      delay(1000);
      while (distance <= 20) { // While the distance stays within 20 remain in the function
        digitalWrite(11, HIGH);
        distance = 0.01723 * readUltrasonicDistance(13, 12);
      }
    }
    digitalWrite(11, LOW);
  }
  digitalWrite(9, LOW);
}

void pushButton() {
  buttonState = digitalRead(3); // Read the value of the button
  if (buttonState == HIGH){ // Run this function if the button is pressed
    digitalWrite(9, HIGH);
    delay(5000);
    digitalWrite(9, LOW);
    delay(1000);
  }
}
