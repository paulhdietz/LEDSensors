//  Alternately sense and flash LED
// Copyright 2018, Paul H. Dietz

// LED Connections
#define PLUS 3
#define MINUS 4

void setup() {
  Serial.begin(250000);       // Initialize serial communication
  
  pinMode(MINUS, OUTPUT);     // Set MINUS pin to output
  pinMode(PLUS, OUTPUT);      // Set PLUS pin to output
}

void loop() {
  unsigned long time;

  digitalWrite(MINUS, HIGH);  // Reverse bias LED
  digitalWrite(PLUS, LOW);
  
  delay(1);                   // wait a ms to charge capacitance

  time = micros();            // Grab the current time

  pinMode(PLUS, INPUT);       // Let go of LED and allow it to discharge

  while (!digitalRead(PLUS)); // wait for PLUS to go HIGH

  time = micros() - time;     // How long has it been?

  pinMode(PLUS, OUTPUT);      // Turn on LED
  digitalWrite(MINUS, LOW);
  digitalWrite(PLUS, HIGH);

  delay(1);

  Serial.println(time);       // Output the elapsed time
}
