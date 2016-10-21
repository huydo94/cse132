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
    int sum = 0;
    for(int j = 0; j < NUM_TAPS; j++) {
      sum = filterAtIndex(i - j, j, sum);
    }

    Serial.print(input1[i]);
    Serial.print(",");
    Serial.print((int)sum);
    Serial.println();
  }

  Serial.println("Done.");
}

void loop() { /* unused */ }
