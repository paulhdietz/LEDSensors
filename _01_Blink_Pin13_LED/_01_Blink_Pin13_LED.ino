//  Blink Pin 13 LED

#define LED 13    // On-board LED is on Pin 13

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                // wait for 1/4 second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                // wait for 1/4 second
}
