#include "qOperations.h"

#define NUMBER_TESTS 10

void setup() {
  Serial.begin(9600);
  Serial.println("Starting program...");

  // Seed the random number generator using the noise from a
  // disconnected sensor
  randomSeed(analogRead(0));

  Serial.println("a\t(dec)\t*\tb\t(dec)\t=\tc\t(dec)");
  for(int i = 0; i < NUMBER_TESTS; i++) {
    unsigned int a = random(0, 65536);
    unsigned int b = random(0, 65536);
    int frac = 15;

    Serial.print(a);
    Serial.print("\t(");
    Serial.print(qtof(a, frac));
    Serial.print(")\t*\t");
    Serial.print(b);
    Serial.print("\t(");
    Serial.print(qtof(b, frac));
    Serial.print(")\t=\t");

    unsigned long c = qMultiply(a, b, frac);
    Serial.print(c);
    Serial.print("\t(");
    Serial.print(qtof(c, frac));
    Serial.print(")");

    if(qtof(a, frac) > 1 && qtof(b, frac) > 1) {
      Serial.print("\tOverflow expected here.");
    }
    
    Serial.println();
  }
}

void loop() { /* unused */ }
