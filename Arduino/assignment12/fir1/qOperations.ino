float qtof(int number, int fractionalBits) {
  // TODO complete
  
  return number/pow(2,fractionalBits);
}

int ftoq(float number, int fractionalBits) {
  // TODO complete
  float huy = number*pow(2,fractionalBits);
  int huyrounded = (int) (huy+0.5);
  return huyrounded;
}


int qMultiply(int a, int b, int fractionalBits) {
// TODO complete
long prod = (long) a*b; //multiplying two ints will cause overflow -> need to use long
int prod1 = prod >> fractionalBits;
return prod1;
}


