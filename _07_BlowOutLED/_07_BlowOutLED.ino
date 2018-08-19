// Blow Out LED Ave creates an LED that you can blow out. It automatically relights
// Many ADC readings are used to reduce noise
// Copyright 2018, Paul H. Dietz

// LED Connections
#define PLUS A1               // High side of the resistor
#define MEASURE A0            // Low side of resistor and anode of LED
// Cathode of LED goes to ground

#define NUMSAMPLES 10         // Number of samples to keep
#define MINJUMP 150           // Minimum jump for blow out

long int sensedata[NUMSAMPLES];
int dataptr = 0;
int buffull = 0;

void setup() {
  Serial.begin(250000);                     // Initialize serial communication
  pinMode(MEASURE, INPUT);
  pinMode(PLUS, OUTPUT);
  digitalWrite(PLUS, HIGH);                 // Turn on the LED
}

void loop() {
  int cnt;
  long int sum = 0;

  // Sum 256 adc readings (to reduce adc noise)
  for (cnt = 0; cnt < 256; cnt++) {
    sum = sum + analogRead(MEASURE);
  }
  
  Serial.println(sum);                      // Output sum so we can watch with Serial Plotter

  // Compare current measurement to oldest if buffer full
  if (buffull && (sum > (sensedata[dataptr] + MINJUMP))) {
    // Temperature drop exceeded minimum - turn off
    digitalWrite(PLUS, LOW);
    dataptr = 0;                            // Reinitialize the buffer
    buffull = 0;
    delay(2000);                            // off time for LED
    digitalWrite(PLUS, HIGH);
  }
  else {
    sensedata[dataptr] = sum;               // Store the latest data in the buffer
    dataptr++;                              // Update buffer pointer
    if (dataptr == NUMSAMPLES) {            // Check if dataptr went past end
      dataptr = 0;                          // Reset the dataptr to beginning
      buffull = 1;                          // Mark that buffer is full
    }
  }
}
