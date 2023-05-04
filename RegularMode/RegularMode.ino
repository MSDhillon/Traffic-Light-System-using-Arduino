void setup()
{
  pinMode(13, OUTPUT); // Define PIN 13 as an OUTPUT
  pinMode(12, OUTPUT); // Define PIN 12 as an OUTPUT
  pinMode(8, OUTPUT); // Define PIN 8 as an OUTPUT
}

void loop()
{
  digitalWrite(8, HIGH); // Turn on LED connected to PIN 8
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(8, LOW); // Turn off LED connected to PIN 8
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(12, HIGH); // Turn on LED connected to PIN 12
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW); // Turn off LED connected to PIN 12
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(13, HIGH); // Turn on LED connected to PIN 13
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(13, LOW); // Turn off LED connected to PIN 13
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(12, HIGH); // Turn on LED connected to PIN 12
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, LOW); // Turn off LED connected to PIN 12
  delay(1000); // Wait for 1000 millisecond(s)
}
