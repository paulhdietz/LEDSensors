// Graph Hot LED Vf graphs the forward voltage drop of an LED
// Copyright 2018, Paul H. Dietz

// LED Connections
#define PLUS A1
#define MEASURE A0

void setup() {
  Serial.begin(250000);       // Initialize serial communication
  pinMode(MEASURE, INPUT);
  pinMode(PLUS, OUTPUT);
  digitalWrite(PLUS, HIGH);   // Turn on the LED
}

void loop() {
  int adc;

  adc = analogRead(MEASURE);

  Serial.println(adc);

  delay(10);
}
