// Filter values for our FIR filter
// Created using FIRExample.m

#define NUM_TAPS 27
// Low pass filter with corner at 20
int fir1[NUM_TAPS] = {
  234,
  -33,
  -188,
  -404,
  -600,
  -663,
  -476,
  43,
  904,
  2027,
  3248,
  4350,
  5117,
  5392,
  5117,
  4350,
  3248,
  2027,
  904,
  43,
  -476,
  -663,
  -600,
  -404,
  -188,
  -33,
  234
};
