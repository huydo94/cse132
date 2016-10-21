#include "filterValues.h"
#include "inputValues.h"

#include "qOperations.h"
#include "assembly.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Starting program...");

  // For each sample...
  for(int i = NUM_TAPS - 1; i < NUM_SAMPS; i++) {
    // ... go over the last NUM_TAPS samples and sum the result.
    int sum = filterLoop(i);
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(input1[i]);
    Serial.print(",");
    Serial.print((int)sum);
    Serial.println();
  }

  Serial.println("Done.");
}

void loop() { /* unused */ }
