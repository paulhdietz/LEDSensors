//  Graph Light level received by LED using Serial Plotter
// Copyright 2018, Paul H. Dietz

// LED Connections
#define PLUS 3
#define MINUS 4

void setup() {
  Serial.begin(250000);       // Initialize serial communication
  
  pinMode(MINUS, OUTPUT);     // Set MINUS pin to output
  pinMode(PLUS, OUTPUT);      // Set PLUS pin to output
  
  digitalWrite(MINUS, HIGH);  // Reverse bias LED
  digitalWrite(PLUS, LOW);
}

void loop() {
  unsigned long time;

  delay(1);                   // wait a ms to charge capacitance

  time = micros();            // Grab the current time

  pinMode(PLUS, INPUT);       // Let go of LED and allow it to discharge

  while (!digitalRead(PLUS)); // wait for PLUS to go HIGH

  time = micros() - time;     // How long has it been?

  Serial.println(time);       // Output the elapsed time

  pinMode(PLUS, OUTPUT);      // Reverse bias the LED again
}
