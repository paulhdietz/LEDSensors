// Automatic Night Light
// Copyright 2018, Paul H. Dietz

// LED Connections
#define PLUS 3
#define MINUS 4

void setup()
{
  pinMode(MINUS, OUTPUT);     // Set MINUS pin to output
  pinMode(PLUS, OUTPUT);      // Set PLUS pin to output
}

void loop()
{
  digitalWrite(PLUS, LOW);    // Reverse bias the LED
  digitalWrite(MINUS, HIGH);

  delay(1);                   // wait a ms to charge capacitance
  pinMode(PLUS, INPUT);       // Let go of LED and allow it to discharge

  delay(15);                  // Wait

  if (digitalRead(PLUS)) {    // Check if charged past logic threshold
    pinMode(PLUS, OUTPUT);    // Yes, light detected so leave PLUS output low
  }
  else {
    pinMode(PLUS, OUTPUT);    // No, turn PLUS to high
    digitalWrite(PLUS, HIGH);
  }

  digitalWrite(MINUS, LOW);

  delay(1);
}
