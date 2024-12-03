const int soilPin = A0;     // Analog pin connected to the soil sensor
const int greenLED = 10;    // Green LED pin
const int yellowLED = 9;    // Yellow LED pin
const int redLED = 8;       // Red LED pin

int dryThreshold = 600;     // Value above which the soil is too dry
int moderateThreshold = 400; // Value between moderate and moist

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);       // Initialize Serial Monitor
}

void loop() {
  int soilMoistureValue = analogRead(soilPin); // Read sensor value
  Serial.println(soilMoistureValue);           // Output value to Serial Monitor

  // Soil is moist
  if (soilMoistureValue < moderateThreshold) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
  // Soil is moderately dry
  else if (soilMoistureValue < dryThreshold) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  // Soil is too dry
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  delay(1000); // Wait for 1 second before reading again
}
